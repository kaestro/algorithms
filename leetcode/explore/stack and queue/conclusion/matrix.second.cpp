#include <vector>
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
                if (col == 0 && visited.find({row, col}) == visited.end()) {
                    visited.insert({row, col});
                    fill_matrix(row, col);
                    //show_shortest_dists();
                }
            }
        }
    }

    inline bool in_matrix(int row, int col) {
        return row >= 0 && row < row_size && col >= 0 && col < col_size;
    }

    void fill_matrix(int row, int col) {
        int nr, nc;
        for (int d = 0; d < dr.size(); ++d) {
            nr = row + dr[d], nc = col + dc[d];
            if (!in_matrix(nr, nc)) continue;
            if (copy_matrix[nr][nc] == 0) {
                if(visited.find({nr, nc}) == visited.end())
                    fill_matrix(nr, nc);
            } else if (shortest_dists[nr][nc] > shortest_dists[row][col] + 1) {
                shortest_dists[nr][nc] = shortest_dists[row][col] + 1;
            }
        }
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