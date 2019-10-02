#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int maxSize = 20;

typedef vector< int > vi;
typedef set < int > si;
typedef pair < int, int > ii;

int mapSize;
int answer;

si visited;
vector < vi > map(maxSize, vi(maxSize, 0));

void reset();
void read();
void solution();

int main() {
    int T;
    freopen("2105.txt", "r", stdin);
    cin >> T;
    for (auto testcase = 1; testcase <= T; ++testcase) {
        reset();
        cin >> mapSize;
        read();
        solution();
        cout << "#" << testcase << " " << answer << endl;
    }

    return 0;
}

void reset() {
    mapSize = 0;
    answer = -1;
    visited.clear();
}

void read() {
    for (auto row = 0; row < mapSize; ++row) {
        for (auto col = 0; col < mapSize; ++col) {
            cin >> map[row][col];
        }
    }
}

inline bool checkBoundary(const int& row, const int& col, const int& width, const int& height) {
    return (width + height) * 2 > answer && (col + width < mapSize) && (row + width + height < mapSize) && (col - height) >= 0;
}

bool checkDessert(const ii& point) {
    int dessert = map[point.first][point.second];
    if (visited.find(dessert) != visited.end()) {
        return true;
    } else {
        visited.insert(dessert);
        return false;
    }
}

void solution() {
    for (auto row = 0; row < mapSize - 2; ++row) {
        for (auto col = 1; col < mapSize - 1; ++col) {
            for (auto width = 1; width < mapSize; ++width) {
                for (auto height = 1; height < mapSize; ++height) {
                    if (!checkBoundary(row, col, width, height)) continue;
                    visited.clear();
                    ii point = {row, col};
                    bool isAble = true;
                    for (auto w = 0; w < width; ++w) {
                        if (checkDessert(point)) {
                            isAble = false;
                            break;
                        }
                        point.first++, point.second++;
                    }

                    if (!isAble) continue;

                    for (auto h = 0; h < height; ++h) {
                        if (checkDessert(point)) {
                            isAble = false;
                            break;
                        }
                        point.first++, point.second--;
                    }

                    if (!isAble) continue;

                    for (auto w = 0; w < width; ++w) {
                        if (checkDessert(point)) {
                            isAble = false;
                            break;
                        }
                        point.first--, point.second--;
                    }

                    if (!isAble) continue;

                    for (auto h = 0; h < height; ++h) {
                        if (checkDessert(point)) {
                            isAble = false;
                            break;
                        }
                        point.first--, point.second++;
                    }

                    if (!isAble) continue;

                    answer = 2 * (width + height);
                }
            }
        }
    }
}


