#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxMap = 20, maxPay = 10;

int mapSize, payment;
int map[maxMap][maxMap];

void read();
bool checkBox(const int& row, const int& col);
void solution();
int checkMap(int step, int row, int col);
void checkStep(int step, int row, int col);
int answer;

int main() {
    int T;
    //freopen("2117.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        read();
        solution();
        cout << "#" << testcase << " " << answer << endl;
    }
}

void read() {
    cin >> mapSize >> payment;
    answer = 0;
    for (int row = 0; row < mapSize; ++row) {
        for (int col = 0; col < mapSize; ++col) {
            cin >> map[row][col];
        }
    }
}

bool checkBox(const int& row, const int& col) {
    if (row < 0 || row >= mapSize || col < 0 || col >= mapSize) return 0;
    if (map[row][col] == 0) return false;
    else return true;
}

void solution() {
    //int maxStep = (mapSize - 1) / 2 + 1;
    int maxStep = (mapSize / 2) * 2 + 1;
    for (int step = 0; step < maxStep; ++step) {
        for (int row = 0; row < mapSize; ++row) {
            for (int col = 0; col < mapSize; ++col) {
                checkStep(step, row, col);
            }
        }
    }
}

void checkStep(int step, int row, int col) {
    int step_plus = step + 1;
    int numHouse = 0;
    int cost = 2 * (step_plus * step_plus - step_plus) + 1;
    for (int rowdiff = -step; rowdiff <= step; ++rowdiff) {
        for (int coldiff = -(step - abs(rowdiff)); coldiff <= step - abs(rowdiff); ++coldiff) {
            if (checkBox(row + rowdiff, col + coldiff)) {
                numHouse++;
            }
        }
    }
    /*
    for (int rowdiff = -(stepSize - 1); rowdiff <= (stepSize - 1); ++rowdiff) {
        for (int coldiff = -(stepSize - abs(rowdiff)); coldiff <= stepSize - abs(rowdiff); ++coldiff) {
            if (checkBox(row + rowdiff, col + coldiff)) {
                numHouse++;
            }
        }
    }
    */
    if (cost <= numHouse * payment) {
        if (numHouse > answer) {
            answer = numHouse;
        }
    }
}