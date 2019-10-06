#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

const int maxMap = 100;
const int blackhole = -1;
const int wormholeOffset = 6;
const int drow[4] = {-1, 0, 1, 0};
const int dcol[4] = {0, 1, 0, -1};

typedef pair< int, int > ii;

vector< vector< ii > > wormHole;
int map[maxMap][maxMap];
int mapSize;
int ans;
int startRow, startCol;

void reset();
void read();
void dfs();
void dfs(const int& row, const int& col, int dir, int curLength);
void visit(const int& boxNo, int& dir, int& nrow, int& ncol);
void solution();

int main() {
    int T;
    //freopen("5650.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        reset();
        read();
        solution();
        cout << "#" << testcase << " " << ans << endl;
    }
}

void reset() {
    ans = 0;
    mapSize = 0;
    wormHole.clear();
    wormHole = vector< vector< ii > >(5);
    startRow = startCol = 0;
}

void read() {
    cin >> mapSize;
    for (int row = 0; row < mapSize; ++row) {
        for (int col = 0; col < mapSize; ++col) {
            cin >> map[row][col];
            if (map[row][col] >= wormholeOffset) {
                wormHole[map[row][col] - wormholeOffset].push_back({row,col});
            }
        }
    }
}

inline void revertDirection(int& dir) {
    dir = (dir + 2) % 4;
}

void visit(const int& boxNo, int& dir, int& nrow, int& ncol) {
    switch(boxNo) {
        case 5:
            revertDirection(dir);
            break;
        case 1:
            if (dir == UP || dir == RIGHT) {
                revertDirection(dir);
            } else if (dir == LEFT) {
                dir = UP;
            } else if (dir == DOWN){
                dir = RIGHT;
            }
            break;
        case 2:
            if (dir == DOWN || dir == RIGHT) {
                revertDirection(dir);
            } else if (dir == LEFT) {
                dir = DOWN;
            } else if (dir == UP) {
                dir = RIGHT;
            }
            break;
        case 3:
            if (dir == DOWN || dir == LEFT) {
                revertDirection(dir);
            } else if (dir == UP) {
                dir = LEFT;
            } else if (dir == RIGHT) {
                dir = DOWN;
            }
            break;
        case 4:
            if (dir == UP || dir == LEFT) {
                revertDirection(dir);
            } else if (dir == RIGHT) {
                dir = UP;
            } else if (dir == DOWN) {
                dir = LEFT;
            }
            break;
        default:
            vector< ii >& wh = wormHole[boxNo - wormholeOffset];
            if (wh[0].first == nrow && wh[0].second) {
                nrow = wh[1].first;
                ncol = wh[1].second;
            } else {
                nrow = wh[0].first;
                ncol = wh[0].second;
            }
            break;
    }
}

inline bool outBoundary(const int& nrow, const int& ncol) {
    return nrow < 0 || nrow >= mapSize || ncol < 0 || ncol >= mapSize;
}

void dfs(const int& row, const int& col, int dir, int curLength) {
    if (curLength > ans)
        ans = curLength;
    int nrow = row + drow[dir];
    int ncol = col + dcol[dir];
    
    if (nrow == startRow && ncol == startCol) return;
    int val = map[nrow][ncol];

    if (val == blackhole) return;

    if (outBoundary(nrow, ncol)) {
        revertDirection(dir);
        curLength++;
        /*
        nrow = row, ncol = col;
        int curVal = map[row][col];
        if (curVal != 0) {
            visit(curVal, dir, nrow, ncol);
            curLength++;
        }
        */
    } else if (val != 0) {
        visit(val, dir, nrow, ncol);
        if (val < wormholeOffset)
            curLength++;
    }
    dfs(nrow, ncol, dir, curLength);
}

void solution() {
    for (int row = 0; row < mapSize; ++row) {
        for (int col = 0; col < mapSize; ++col) {
            if (map[row][col] == 0) {
                startRow = row, startCol = col;
                for (int d = 0; d < 4; ++d) {
                    dfs(row, col, d, 0);
                }
            }
        }
    }
}