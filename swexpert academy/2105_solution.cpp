#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

typedef vector< int > vi;
typedef vector< bool > vb;

vector< vi > map;
vb visited;
int mapSize;
int result;

void read();
void reset();
void solve();

int main() {
    int T;
    freopen("2105.txt", "r", stdin);
    cin >> T;
    for (auto testcase = 1; testcase <= T; ++testcase) {
        reset();
        cin >> mapSize;
        read();
        solve();

        cout << "#" << testcase << " " << result << endl;
    }

    return 0;
}

void read() {
    map = vector< vi >(mapSize, vi(mapSize, 0));

    for (auto row = 0; row < mapSize; ++row) {
        for (auto col = 0; col < mapSize; ++col) {
            cin >> map[row][col];
        }
    }
}

void reset() {
    mapSize = 0;
    map.clear();
    visited.clear();
    visited = vb(101, false);
    result = -1;
}

inline bool checkBoundary(int row, int col, int width, int height) {
    return ((width + height) * 2 > result && col + width < mapSize && row + width + height < mapSize && col - height >= 0);
}

bool checkVisited(int row, int col) {
    if (visited[map[row][col]]) {
        return true;
    } else {
        visited[map[row][col]] = true;
        return false;
    }
}

void solve() {
    for (auto row = 0; row < mapSize; ++row) {
        for (auto col = 0; col < mapSize; ++col) {
            for (auto width = 1; width < mapSize; ++width) {
                for (auto height = 1; height < mapSize; ++height) {
                    if (checkBoundary(row, col, width, height)) {
                        visited.clear();
                        visited = vb(101, false);
                        bool isAble = true;
                        int curRow = row, curCol = col;
                        for (auto n = 0; n < width; ++n) {
                            curRow++, curCol++;
                            isAble = !checkVisited(curRow, curCol);
                            if (!isAble)
                                break;
                        }

                        if (!isAble) continue;

                        for (auto h = 0; h < height; ++h) {
                            curRow++, curCol--;
                            isAble = !checkVisited(curRow, curCol);
                            if (!isAble)
                                break;
                        }

                        if (!isAble) continue;

                        for (auto w = 0; w < width; ++w) {
                            curRow--, curCol--;
                            isAble = !checkVisited(curRow, curCol);
                            if (!isAble)
                                break;
                        }

                        if (!isAble) continue;

                        for (auto h = 0; h < height; ++h) {
                            curRow--, curCol++;
                            isAble = !checkVisited(curRow, curCol);
                            if (!isAble)
                                break;
                        }
                        if (!isAble) continue;

                        result = 2 * (width + height);
                    }
                }
            }
        }
    }
}

