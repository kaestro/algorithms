#include <string>
#include <vector>
#include <queue>

using namespace std;

class robot {
 public:
    robot(int row, int col, bool isHorizontal)
    :row(row), col(col), isHorizontal(isHorizontal)
    {}

    int row, col;
    bool isHorizontal;

    void passed_point();
    bool reached_end();
};

using bb = pair<bool, bool>;
using vi = vector<int>;
using qr = queue<robot>;

// first is for horizontal, second is for vertical robot
vector<vector<pair<bool, bool>>> robot_used; 
int board_size;
const bool hRobot = true, vRobot = false;



bool reached_end(robot& next_robot);
void create_next_robots(qr& next_queue, const robot& cur_robot, const vector<vi>& board);
void initialize(int input_size);
void create_next_from_vertical(qr& next_queue, const robot& cur_robot, const vector<vi>& board);
void create_next_from_horizontal(qr& next_queue, const robot& cur_robot, const vector<vi>& board);
int solution(vector<vi> board);

int main() {
    vector<vector<int>> board = {
        {0,0,0,1,1},
        {0,0,0,1,0},
        {0,1,0,1,1},
        {1,1,0,0,1},
        {0,0,0,0,0}
    };
    solution(board);

    return 0;
}

int solution(vector<vi> board) {
    int answer = 0;
    initialize(board.size());
    queue<robot> robot_queue;
    robot first(1, 1, true);
    // TODO
    // TEST robot_reached end by initializing
    // value of first to be n - 1, n - 2, true
    // n - 2, n - 1, false
    robot_queue.push(first);
    while (!robot_queue.empty())
    {
        answer++;
        queue<robot> next_queue;
        while (!robot_queue.empty())
        {
            auto next_robot = robot_queue.front();
            robot_queue.pop();
            next_robot.passed_point();

            if (next_robot.reached_end()) return answer;

            create_next_robots(next_queue, next_robot, board);
        }
        robot_queue = next_queue;
    }
    return answer;
}

void initialize(int input_size) {
    board_size = input_size;
    robot_used = vector<vector<bb>>(board_size, vector<bb>(board_size));
}

void create_next_robots(qr& next_queue, const robot& cur_robot, const vector<vi>& board) {
    if (cur_robot.isHorizontal)
        create_next_from_horizontal(next_queue, cur_robot, board);
    else
        create_next_from_vertical(next_queue, cur_robot, board);
}

inline bool is_robot_queable(int row, int col, bool isHorizontal) {
    if (isHorizontal)
        return robot_used[row][col].first;
    else
        return robot_used[row][col].second;
}

void create_next_from_horizontal(qr& nq, const robot& cur_robot, const vector<vi>& board) {
    int row = cur_robot.row, col = cur_robot.col;
    
    // vertical robot creation
    if (row != 0)
    {
        if (board[row - 1][col] == 0 && board[row - 1][col + 1] == 0)
        {
            // TODO
            // create a function that receives row, column, ishorizontal.
            // return if it's false and change it's original value
            if (is_robot_queable(row - 1, col, vRobot))
            {
                robot_used[row - 1][col].second = true;
                nq.push(robot(row - 1, col, false));
            }
            if (is_robot_queable(row - 1, col + 1, vRobot)) {
                robot_used[row - 1][col + 1].second = true;
                nq.push(robot(row - 1, col + 1, false));
            }
        }
    }

    if (row != board_size - 1)
    {
        if (board[row + 1][col] == 0 && board[row + 1][col + 1] == 0)
        {
            if (is_robot_queable(row, col, vRobot))
            {
                // TODO
                // better to create another class that push implicitly deals with
                // used check and transformation
                robot_used[row][col].second = true;
                nq.push(robot(row, col, false));
            }
            if (is_robot_queable(row, col + 1, vRobot))
            {
                robot_used[row][col + 1].second = true;
                nq.push(robot(row, col + 1, false));
            }
        }
    }

    // horizontal robot creation
    if (col != 0)
    {
        if (board[row][col - 1] == 0)
        {
            if (is_robot_queable(row, col - 1, hRobot))
            {
                robot_used[row][col - 1].first = true;
                nq.push(robot(row, col -1, hRobot));
            }
        }
    }
    
    if (col < board_size - 2)
    {
        if (board[row][col + 1] == 0)
        {
            if (is_robot_queable(row, col + 1, hRobot))
            {
                robot_used[row][col + 1].first = true;
                nq.push(robot(row, col + 1, hRobot));
            }
        }
    }
}

void create_next_from_vertical(qr& nq, const robot& cur_robot, const vector<vi>& board)
{
    int row = cur_robot.row, col = cur_robot.col;

    // creating vertical
    if (row != 0)
    {
        if (board[row - 1][col] == 0)
        {
            if (is_robot_queable(row - 1, col, vRobot))
            {
                robot_used[row - 1][col].second = true;
                nq.push(robot(row - 1, col, vRobot));
            }
        }
    }

    if (row < board_size - 2)
    {
        if (board[row + 2][col] == 0)
        {
            if (is_robot_queable(row + 1, col, vRobot))
            {
                robot_used[row + 1][col].second = true;
                nq.push(robot(row + 1, col, vRobot));
            }
        }
    }

    // creating horizontal
}


void robot::passed_point() {
    if (isHorizontal)
        robot_used[row][col].first = true;
    else
        robot_used[row][col].second = true;
}

bool robot::reached_end() {
    if (isHorizontal)
        return (row == board_size - 1) && (col == board_size - 2);
    else
        return (row == board_size - 2) && (col == board_size - 1);
}
