#include <iostream>
#include <cstdio>

using namespace std;

const int maxLength = 8;
const int maxDepth = 5;

const int drow[4] = {-1, 0, 1, 0};
const int dcol[4] = {0, 1, 0, -1};

int mapSize, digDepth;
int map[maxLength][maxLength];
bool visited[maxLength][maxLength];
int ans;
int highest;

void reset();
void read();
void dfs(int row, int col, int length, bool digged);
void solution();

int main() {
    int T;
    freopen("1949.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        reset();
        read();
        solution();
        cout << "#" << testcase << " " << ans << endl;
    }
}


void reset() {
    mapSize = digDepth = ans = 0;
    highest = 0;
}

void read() {
    cin >> mapSize >> digDepth;
    for (int row = 0; row < mapSize; ++row) {
        for (int col = 0; col < mapSize; ++col) {
            cin >> map[row][col];
            if (map[row][col] > highest)
                highest = map[row][col];
            visited[row][col] = false;
        }
    }
}

inline bool outBoundary(const int& row, const int& col) {
    return row < 0 || row >= mapSize || col < 0 || col >= mapSize;
}

void dfs(int row, int col, int length, bool digged) {
    if (length > ans)
        ans = length;
    
    int curHeight = map[row][col];
    visited[row][col] = true;
    
    for (int d = 0; d < 4; ++d) {
        int nrow = row + drow[d];
        int ncol = col + dcol[d];
        if (outBoundary(nrow, ncol) || visited[nrow][ncol]) continue;

        int nHeight = map[nrow][ncol];
        if (nHeight < curHeight) {
            dfs(nrow, ncol, length + 1, digged);
        } else if (!digged && (nHeight - digDepth) < curHeight) {
            map[nrow][ncol] = curHeight - 1;
            dfs(nrow, ncol, length + 1, true);
            map[nrow][ncol] = nHeight;
        }
    }
    visited[row][col] = false;
}

void solution() {
    for (int row = 0; row < mapSize; ++row) {
        for (int col = 0; col < mapSize; ++col) {
            if (map[row][col] == highest) {
                dfs(row, col, 1, false);
            }
        }
    }
}