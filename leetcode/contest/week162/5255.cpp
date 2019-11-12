#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int row_size, int col_size, vector<vector<int>>& indices) {
        vector<vector<int>> matrix;
        matrix.resize(row_size);
        for (int row = 0; row < row_size; ++row) {
            matrix[row].resize(col_size);
        }
        for (auto indice : indices) {
            for (int col = 0; col < col_size; ++col)  {
                ++matrix[indice[0]][col];
            }
            for (int row = 0; row < row_size; ++row) {
                ++matrix[row][indice[1]];
            }
        }
        int ans = 0;
        for (int row = 0; row < row_size; ++row) {
            for (int col = 0; col < col_size; ++col) {
                ans += matrix[row][col] % 2;
            }
        }
        return ans;
    }
};