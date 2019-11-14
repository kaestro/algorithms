#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using ii = std::pair<int, int>;

class Solution {
private:
    vvi shortest_dists, copy_matrix;
    int row_size, col_size;
    const vi dr = {-1, 0, 1, 0};
    const vi dc = {0, 1, 0, -1};
    std::set<ii> visited;
public:
    vvi updateMatrix(vvi& matrix) {
        if(!initializable(matrix)) return matrix;
        calculate_dists();
        return shortest_dists;
    }

    bool initializable(vvi& matrix) {
        row_size = matrix.size();
        if (row_size == 0) return false;
        col_size = matrix[0].size();

        copy_matrix = matrix;

        shortest_dists.resize(row_size);
        for (int i = 0; i < row_size; ++i) {
            shortest_dists[i].resize(col_size);
        }

        return true;
    }

    void calculate_dists() {
        for (int row = 0; row < row_size; ++row) {
            for (int col = 0; col < col_size; ++col) {
                if (copy_matrix[row][col] == 0) continue;
                else if (visited.find({row,col}) == visited.end()){
                    visited.insert({row,col});
                    shortest_dists[row][col] = get_sd(row, col);
                    show_shortest_dists();
                }
            }
        }
    }

    inline bool in_matrix(int row, int col) {
        return row >= 0 && row < row_size && col >= 0 && col < col_size;
    }

    // get the shortest distance from 0 to matrix[row][col]
    int get_sd(int row, int col) {
        if (copy_matrix[row][col] == 0) return 0;
        if (shortest_dists[row][col] != 0) return shortest_dists[row][col];

        int nr, nc;
        vi sd_others;
        for (int d = 0; d < dr.size(); ++d) {
            nr = row + dr[d], nc = col + dc[d];
            if (in_matrix(nr, nc)) {
                if (copy_matrix[nr][nc] == 0) return 1;

                if (visited.find({nr, nc}) == visited.end()) {
                    visited.insert({nr,nc});
                    shortest_dists[nr][nc] = get_sd(nr,nc);
                }
                sd_others.push_back(shortest_dists[nr][nc]);
            }
        }

        return *std::min_element(sd_others.begin(), sd_others.end()) + 1;
    }

    void show_shortest_dists() {
        for (int r = 0; r < row_size; ++r) {
            for (int c = 0; c < col_size; ++c) {
                std::cout << shortest_dists[r][c] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

int main() {
    vvi matrix = {
        {0,1,0,1,1},
        {1,1,0,0,1},
        {0,0,0,1,0},
        {1,0,1,1,1},
        {1,0,0,0,1}
    };
    Solution s;
    auto ans = s.updateMatrix(matrix);
    return 0;
}