#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> map = grid;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 1; r < rows; ++r) {
            map[r][0] += map[r-1][0];
        }

        for (int c = 1; c < cols; ++c) {
            map[0][c] += map[0][c-1];
        }

        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                map[r][c] += min(map[r-1][c], map[r][c-1]);
            }
        }

        return map[rows-1][cols-1];
    }
};

// my first idea.
/*
class Solution {
private:
    int min_val;
    int max_row, max_col;
public:
    int minPathSum(vector<vector<int>>& grid) {
        min_val = 0x7fff;
        max_row = grid.size();
        if (max_row == 0) return 0;
        max_col = grid[0].size();
        find_path(grid, 0, 0, 0);
        return min_val;
    }

    void find_path(vector<vector<int>>& grid, int row, int col, int sum) {
        sum += grid[row][col];
        if (row == max_row - 1 && col == max_col - 1) {
            min_val = min(sum, min_val);
        } else if (row == max_row - 1) {
            find_path(grid, row, col+1, sum);
        } else if (col == max_col - 1) {
            find_path(grid, row+1, col, sum);
        } else {
            find_path(grid, row+1, col, sum);
            find_path(grid, row, col+1, sum);
        }
    }
};
*/