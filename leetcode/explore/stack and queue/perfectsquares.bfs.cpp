#include <queue>
#include <vector>

class Solution {
 private:
    std::vector<int> squares;
    int goal;
 public:
    int numSquares(int n) {
        if (n < 1) return 0;
        goal = n;
        set_square();
        return bfs();
    }
    void set_square() {
        int i = 0, square;
        while (true)
        {
            i++;
            square = i * i;
            if (square > goal) break;
            squares.push_back(square);
        }
    }

    int bfs() {
        std::queue<int> next_goal;
        next_goal.push(goal);
        int cur_goal, q_size;
        int num_squares = 0;
        while (!next_goal.empty())
        {
            q_size = next_goal.size();
            num_squares++;
            for (size_t i = 0; i < q_size; ++i)
            {
                cur_goal = next_goal.front(); next_goal.pop();
                for (auto square : squares) {
                    if (cur_goal == square) {
                        return num_squares;
                    }
                    if (cur_goal > square) {
                        next_goal.push(cur_goal - square);
                    } else {
                        break;
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    s.numSquares(12);

    return 0;
}