#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector< int > vi;
class bacteria {
 public:
    int number;
    int dirIdx;
};
typedef vector< bacteria > vb;

const vector< vi > direction = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

vector< vector< vb > > map;
int mapSize, hour;
int answer;

void reset() {
    map.clear();
    hour = 0;
    answer = 0;
}

void read();
void solution();
void move();
void collect();
void showMap();

int main() {
    int T;
    freopen("2832.txt", "r", stdin);
    cin >> T;
    for (auto testcase = 1; testcase <= T; ++testcase) {
        reset();
        read();
        solution();
        cout << "#" << testcase << " " << answer << endl;
    }
    return 0;
}

void read() {
    int numBacteria;
    cin >> mapSize >> hour >> numBacteria;
    map = vector< vector < vb > >(mapSize, vector< vb >(mapSize));
    for (auto i = 0; i < numBacteria; ++i) {
        int row, col, bNumber, bDirection;
        cin >> row >> col >> bNumber >> bDirection;
        map[row][col].push_back({bNumber, bDirection - 1});
        answer += bNumber;
    }
}

void solution() {
    for (auto t = 0; t < hour; ++t) {
        move();
        collect();
    }
}

inline bool isBoundary(int row, int col) {
    return row == 0 || row == mapSize - 1 || col == 0 || col == mapSize - 1;
}

void revert(int& dirIdx) {
    switch (dirIdx) {
        case 0: dirIdx = 1; break;
        case 1: dirIdx = 0; break;
        case 2: dirIdx = 3; break;
        case 3: dirIdx = 2; break;
        default: cout << "error occurred for dirIdx" << endl;
    }
}

void move() {
    auto newMap = vector< vector < vb > >(mapSize, vector< vb >(mapSize));
    for (auto row = 0; row < mapSize; ++row) {
        for (auto col = 0; col < mapSize; ++col) {
            if (!map[row][col].empty()) {
                auto baci = map[row][col].begin();
                int nrow = row + direction[baci->dirIdx][0];
                int ncol = col + direction[baci->dirIdx][1];
                if (isBoundary(nrow, ncol)) {
                    revert(baci->dirIdx);
                    int diff = baci->number - (baci->number / 2);
                    answer -= diff;
                    baci->number /= 2;
                }
                newMap[nrow][ncol].push_back(*baci);
            }
        }
    }
    map.clear();
    map = newMap;
}

void collect() {
    for (auto row = 0; row < mapSize; ++row) {
        for (auto col = 0; col < mapSize; ++col) {
            if (map[row][col].size() > 1) {
                int maxNo = 0;
                int maxDir = -1;
                int totalNumber = 0;
                for (auto vbi = map[row][col].begin(); vbi != map[row][col].end(); ++vbi){
                    totalNumber += vbi->number;
                    if (vbi->number > maxNo) {
                        maxDir = vbi->dirIdx;
                        maxNo = vbi->number;
                    }
                }
                map[row][col].clear();
                if (maxDir < 0) {
                    cout << "maxDir Error!" << endl;
                }
                map[row][col].push_back({totalNumber, maxDir});
            }
        }
    }
}

void showMap() {
    return;
    for (int row = 0; row < mapSize; ++row) {
        for (int col = 0; col < mapSize; ++col) {
            cout << "(" << row << "," << col << "): ";
            for (auto it = map[row][col].begin(); it != map[row][col].end(); ++it) {
                cout << "[" << it->number << "," << it->dirIdx << "]";
            }
            cout << endl;
        }
    }
    cout << endl;
}


