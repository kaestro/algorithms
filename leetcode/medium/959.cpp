#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector< int > vi;
const vi dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

void cutMap(vector<string>& grid, vector< vi >& map);
void dfs(vector< vi >& map, int row, int col);
int colorMap(vector< vi >& map);

class Solution {
 public:
    int regionsBySlashes(vector<string>& grid) {
        int map_length = 3 * grid[0].length();
        vector< vi > map(map_length, vi(map_length));
        cutMap(grid, map);
        return colorMap(map);
    }
};

int main() {
    // having 2 character \\ doesn't mean it's length is 2.
    // It's read as single character
    vector<string> input = {
          "/\\", "\\/"
    };
    vector<string> input2 = {
        " /","/ "
    };
    Solution s;
    //s.regionsBySlashes(input);
    s.regionsBySlashes(input2);
}

void cutMap(vector<string>& grid, vector< vi >& map){
    int base_row, base_col;
    int grid_length = grid.size();
    for (int row = 0; row < grid_length; ++row) {
        for (int col = 0; col < grid_length; ++col) {
            base_row = 3 * row, base_col = 3 * col;
            if (grid[row][col] == '/') {
                map[base_row][base_col + 2] = -1;
                map[base_row + 1][base_col + 1] = -1;
                map[base_row + 2][base_col] = -1;
            } else if (grid[row][col] != ' ') {
                map[base_row][base_col] = -1;
                map[base_row + 1][base_col + 1] = -1;
                map[base_row + 2][base_col + 2] = -1;
            }
        }
    }
}

void dfs(vector< vi >& map, int row, int col) {
    int next_row, next_col;
    int mapSize = map.size();
    map[row][col] = 1;
    for (int d = 0; d < 4; ++d) {
        next_row = row + dr[d], next_col = col + dc[d];
        if (next_row < 0 || next_row >= mapSize) continue;
        if (next_col < 0 || next_col >= mapSize) continue;

        if (map[next_row][next_col] == 0)
            dfs(map, next_row, next_col);
    }
}

int colorMap(vector< vi >& map) {
    int num_color = 0;
    int map_length = map.size();
    for (int row = 0; row < map_length; ++row) {
        for (int col = 0; col < map_length; ++col) {
            if (map[row][col] == 0) {
                dfs(map, row, col);
                num_color++;
            }
        }
    }
    return num_color;
}