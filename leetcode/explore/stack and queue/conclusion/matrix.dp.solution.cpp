#include <vector>
#include <algorithm>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

class Solution {
public:
    vvi updateMatrix(vvi& matrix) {
        const int row_size = matrix.size();
        if (row_size == 0) return matrix;
        const int col_size = matrix[0].size();
        const int max_int = col_size + row_size;
        vvi dist_mat(row_size, vi(col_size, max_int));

        for (int row = 0; row < row_size; ++row) {
            for (int col = 0; col < col_size; ++col) {
                if (matrix[row][col] == 0) {
                    dist_mat[row][col] = 0;
                }
            }
        }

        for (int row = 0; row < row_size; ++row) {
            for (int col = 0; col < col_size; ++col) {
                if (row > 0) {
                    dist_mat[row][col] = std::min(dist_mat[row][col], dist_mat[row-1][col]+1);
                }
                if (col > 0) {
                    dist_mat[row][col] = std::min(dist_mat[row][col], dist_mat[row][col-1]+1);
                }
            }
        }

        for (int row = row_size-1; row >= 0; --row) {
            for (int col = col_size-1; col >= 0; --col) {
                if (row < row_size-1) {
                    dist_mat[row][col] = std::min(dist_mat[row][col],dist_mat[row+1][col]+1);
                }
                if (col < col_size-1) {
                    dist_mat[row][col] = std::min(dist_mat[row][col],dist_mat[row][col+1]+1);
                }
            }
        }

        return dist_mat;
    }
};