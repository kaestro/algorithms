#include <vector>

using namespace std;

const int Land = 0;
const int Water = 1;


class Solution {
private:
    vector<vector<bool>> visited;
    vector<vector<int>> copy_grid;
    const vector<int> dr = {-1, 0, 1, 0};
    const vector<int> dc = {0, 1, 0, -1};
    int row_size, col_size;
    int noi;
public:
    int closedIsland(vector<vector<int>>& grid) {
        noi = 0;
        copy_grid = grid;
        row_size = grid.size(); col_size = grid[0].size();
        visited.resize(row_size);
        for (int r = 0; r < row_size; ++r) {
            visited[r].resize(col_size);
        }

        for (int row = 0; row < row_size; ++row) {
            for (int col = 0; col < col_size; ++col) {
                if (copy_grid[row][col] == Land && !visited[row][col]) {
                    noi += visit(row, col);
                }
            }
        }
        return noi;
    }

    inline bool is_boundary(int row, int col) {
        return row == 0 || row == row_size-1 || col == 0 || col == col_size-1;
    }

    inline bool out_boundary(int row, int col) {
        return row < 0 || row >= row_size || col < 0 || col >= col_size;
    }

    int visit(int row, int col) {
        visited[row][col] = true;
        int nr, nc;
        int ans = !is_boundary(row, col);
        for (int d = 0; d < 4; ++d) {
            nr = row + dr[d], nc = col + dc[d];
            if (out_boundary(nr, nc)) continue;
            if (copy_grid[nr][nc] == Water) continue;
            if (is_boundary(nr, nc)) {
                ans = 0;
            }
            if (!visited[nr][nc]) {
                ans = min(ans, visit(nr, nc));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    Solution s;

    auto ans = s.closedIsland(grid);

    return 0;
}