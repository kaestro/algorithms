#include <vector>
#include <queue>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using ii = std::pair<int, int>;

class Solution {
private:
    const vi dr = {-1, 0, 1, 0};
    const vi dc = {0, 1, 0, -1};
    int row_size, col_size;
    std::queue<ii> next_coordinates;
public:
    inline bool in_range(int row, int col) {
        return row >= 0 && row < row_size && col >= 0 && col < col_size;
    }

    vvi floodFill(vvi& image, int sr, int sc, int new_color) {
        if (image.size() == 0) return image;
        row_size = image.size(), col_size = image[0].size();

        int cur_color = image[sr][sc];
        if (cur_color == new_color) return image;

        next_coordinates.push({sr, sc});
        while (!next_coordinates.empty()) {
            size_t q_length = next_coordinates.size();
            for (size_t i = 0; i < q_length; ++i) {
                auto rc = next_coordinates.front(); next_coordinates.pop();
                auto row = rc.first, col = rc.second;
                if (image[row][col] == new_color) continue;

                image[row][col] = new_color;
                for (int i = 0; i < dr.size(); ++i) {
                    auto nr = row + dr[i], nc = col + dc[i];
                    if (in_range(nr, nc) && image[nr][nc] == cur_color) {
                        next_coordinates.push({nr, nc});
                    }
                }
            }
        }

        return image;
    }
};