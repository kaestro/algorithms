#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

class Solution {
 private:
    vvi copy_grid;
    int row_size, col_size;
 public:
    vvi shiftGrid(vvi& grid, int k) {
        copy_grid = grid;
        row_size = grid.size();
        if (row_size == 0) return grid;
        col_size = grid[0].size();


        for (int i = 0; i < k; ++i) {
            shift(k);
        }
        return copy_grid;
    }

    void shift(int times) {
        vvi temp_grid;
        temp_grid.resize(row_size);
        for (int row = 0; row < row_size; ++row) {
            temp_grid[row].resize(col_size);
        }

        for (int row = 0; row < row_size; ++row) {
            if (row != row_size - 1) {
                temp_grid[row+1][0] = copy_grid[row][col_size-1];
            } else {
                temp_grid[0][0] = copy_grid[row_size-1][col_size-1];
            }
            for (int col = 0; col < col_size-1; ++col) {
                temp_grid[row][col+1] = copy_grid[row][col];
            }
        }
        copy_grid = temp_grid;
    }
};