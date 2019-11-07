#include <stack>
#include <vector>
#include <iostream>
#include <unordered_set>


class Solution {
private:
    std::unordered_set<int> squares;
    std::vector<int> min_numsquares;
    int goal;
public:
    int numSquares(int n) {
        if (n < 1) return 0;
        goal = n;
        set_square();
        solution();
        return min_numsquares[goal];
    }
    
    void set_square() {
        int i = 0, square;
        while (true)
        {
            i++;
            square = i * i;
            if (square > goal) break;
            squares.insert(square);
        }
    }
    
    void solution() {
        min_numsquares.reserve(goal + 1);
        min_numsquares.push_back(0);
        std::vector<int> t_squares;
        int temp;
        for (int i = 1; i < goal + 1; ++i)
        {
            if (squares.find(i) != squares.end()) {
                min_numsquares.push_back(1);
                t_squares.push_back(i);
            } else {
                temp = 0x0fffffff;
                for (size_t j = 0; j < t_squares.size(); ++j) {
                    temp = std::min(temp, min_numsquares[i - t_squares[j]]);
                }
                min_numsquares.push_back(temp + 1);
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<int> inputs = {
        12, 13
    };

    for (auto input : inputs) {
        std::cout << s.numSquares(input) << std::endl;
    }
    return 0;
}