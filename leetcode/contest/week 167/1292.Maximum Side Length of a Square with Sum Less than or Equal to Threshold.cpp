#include <vector>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row_size = mat[0].size();
        int col_size = mat.size();
        int max_size = max(row_size, col_size);
    }
};