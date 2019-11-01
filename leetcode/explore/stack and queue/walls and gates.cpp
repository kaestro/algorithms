#include <vector>
#include <queue>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

struct room {
    int row, col, value;
    room(int r, int c, int v):
        row(r), col(c), value(v)
        {}
};

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

class Solution {
private:
    queue<room> qr;
    int row_size, col_size;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        row_size = rooms.size();
        if (row_size == 0) return;
        col_size = rooms[0].size();
        if (col_size == 0) return;
        for (int row = 0; row < row_size; ++row)
        {
            for (int col = 0; col < col_size; ++col)
            {
                if (rooms[row][col] == 0) {
                    qr.push(room(row, col, 0));
                }
            }
        }

        bfs(rooms);
    }

    void bfs(vvi& rooms) {
        while (!qr.empty())
        {
            auto front = qr.front();
            qr.pop();
            int next_value = front.value + 1;
            for (int i = 0; i < 4; ++i)
            {
                int nr = front.row + dr[i];
                int nc = front.col + dc[i];

                if (nr < 0 || nr >= row_size) continue;
                if (nc < 0 || nc >= col_size) continue;

                if (rooms[nr][nc] > next_value) {
                    rooms[nr][nc] = next_value;
                    qr.push(room(nr, nc, next_value));
                }
            }
        }
    }
};