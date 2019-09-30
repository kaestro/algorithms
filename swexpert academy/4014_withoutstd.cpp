#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair< int, int > ii;
typedef vector< int > vi;

const int maxSize = 20;

int mapSize, slopeLength;
vector< vi > map(maxSize, vi(maxSize, 0));
vector< vi > horizontalMap(maxSize, vi(maxSize, 0));
vector< vi > verticalMap(maxSize, vi(maxSize, 0));

void read();
void solution();
int answer;

int main() {
    int T;
    freopen("4014.txt", "r", stdin);
    cin >> T;
    for (auto testcase = 1; testcase <= T; ++testcase) {
        read();
        solution();
        cout << "#" << testcase << " " << answer << endl;
    }
}

void read() {
    answer = 0;
    cin >> mapSize >> slopeLength;
    for (auto row = 0; row < mapSize; ++row) {
        for (auto col = 0; col < mapSize; ++col) {
            cin >> map[row][col];
        }
    }
}

void createVF(vector< vector< ii > >& data) {
    for (auto row = 0; row < mapSize; ++row) {
        vector< ii > rowData;
        int height = map[row][0], length = 0;
        for (auto col = 0; col < mapSize; ++col) {
            if (map[row][col] == height) {
                length++;
            } else {
                rowData.push_back({height, length});
                height = map[row][col];
                length = 1;
            }
        }
        rowData.push_back({height, length});
        data.push_back(rowData);
    }

    for (auto col = 0; col < mapSize; ++col) {
        vector< ii > colData;
        int height = map[0][col], length = 0;
        for (auto row = 0; row < mapSize; ++row) {
            if (map[row][col] == height) {
                length++;
            } else {
                colData.push_back({height, length});
                height = map[row][col];
                length = 1;
            }
        }
        colData.push_back({height, length});
        data.push_back(colData);
    }
}

void showVF(const vector< vector< ii > >& data) {
    for (auto v : data) {
        cout << "[";
        for (auto f : v) {
            cout << "(" << f.first << ", " << f.second << "),";
        }
        cout << "]" << endl;
    }
}

inline int abs(int input) {
    return input < 0 ? -input : input;
}

void compare(vector< vector< ii > >& data) {
    for (auto& vf : data) {
        bool available = true;
        for (vector< ii >::iterator it = vf.begin(); it + 1 != vf.end(); ++it) {
            if (abs(it->first - (it + 1)->first) != 1) {
                available = false;
                break;
            } else {
                auto lower = (it->first - (it + 1)->first) < 0 ? it : it + 1;
                if (lower->second < slopeLength) {
                    available = false;
                    break;
                } else {
                    lower->second -= slopeLength;
                }
            }
        }
        if (available) answer++;
    }
}

void solution() {
    vector< vector< pair< int, int > > > data;
    createVF(data);
    //showVF(data);
    compare(data);
}



