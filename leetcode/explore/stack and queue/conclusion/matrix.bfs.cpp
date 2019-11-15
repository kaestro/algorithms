#include <vector>
#include <queue>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using ii = std::pair<int,int>;

const int INT_MAX = 0x7fffffff;

class Solution {
 private:
    vvi dist_mat, copy_mat;
    std::queue<ii> next_startings;
    vvb visited;
    int row_size, col_size;
    const std::vector<int> dr = {-1,0,1,0};
    const std::vector<int> dc = {0,1,0,-1};
 public:

    inline bool in_boundary(int row, int col) {
        return 0 <= row && row < row_size && 0 <= col && col < col_size;
    }

    vvi updateMatrix(vvi& matrix) {
        initialize(matrix);
        
        size_t q_size;
        ii coordinate;
        int row, col, nr, nc;
        int dist = 1;
        while (!next_startings.empty()) {
            q_size = next_startings.size();
            for (size_t i = 0; i < q_size; ++i) {
                coordinate = next_startings.front(); next_startings.pop();
                row = coordinate.first, col = coordinate.second;
                for (size_t d = 0; d < dr.size(); ++d) {
                    nr = row + dr[d], nc = col + dc[d];
                    if (in_boundary(nr, nc) && !visited[nr][nc] && dist_mat[nr][nc] > dist) {
                        dist_mat[nr][nc] = dist;
                        visited[nr][nc] = true;
                        next_startings.push({nr, nc});
                    }
                }
            }
            ++dist;
        }
        return dist_mat;
    }

    void initialize(const vvi& matrix) {
        row_size = matrix.size(), col_size = matrix[0].size();
        copy_mat = matrix;

        dist_mat.resize(row_size), visited.resize(row_size);
        for (int row = 0; row < row_size; ++row) {
            dist_mat[row].resize(col_size), visited[row].resize(col_size);
            for (int col = 0; col < col_size; ++col) {
                if (matrix[row][col] == 0) {
                    visited[row][col] = true;
                    next_startings.push({row,col});
                } else {
                    dist_mat[row][col] = INT_MAX;
                }
            }
        }
    }
};

int main() {

    Solution s;
    vvi input = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    input = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    input = {
        {0,1,1,1},
        {0,1,1,1},
        {1,0,0,1},
        {0,0,1,0}
    };
    auto ans = s.updateMatrix(input);

    return 0;
}
