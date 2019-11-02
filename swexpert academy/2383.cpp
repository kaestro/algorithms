#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxHuman = 10;
const int maxLength = 10;
const int stairLimit = 3;
const int maxStairLength = 10;
const int maxStair = 2;
const int maxAnswer = maxHuman * maxLength * maxLength * maxStairLength;

int stairs[maxStair][maxLength * maxLength][stairLimit];
int stairLength[maxStair];
int stairNo[maxHuman];
int dist[maxStair][maxHuman];
int map[maxLength][maxLength];
int stairPos[maxStair][2];

int numHuman, numStair;
int mapLength;
int answer;

void reset();
void read();
void dfs(int step);
void run();

int main() {
    int T;
    freopen("2383.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        reset();
        read();
        dfs(numHuman);
    }
}

void reset() {
    answer = maxAnswer;
    numHuman = numStair = 0;
}

inline int abs(const int input){
    return input < 0 ? -input : input;
}

void read() {
    cin >> mapLength;
    for (int row = 0; row < mapLength; ++row) {
        for (int col = 0; col < mapLength; ++col) {
            cin >> map[row][col];
            if (map[row][col] > 1) {
                stairPos[numStair][0] = row;
                stairPos[numStair][1] = col;
                numStair++;
            }
        }
    }

    int nrow, ncol;
    int curHuman = 0;
    for (int row = 0; row < mapLength; ++row) {
        for (int col = 0; col < mapLength; ++col) {
            if (map[row][col] == 1) {
                for (int i = 0; i < numStair; ++i) {
                    dist[numStair][curHuman++] = abs(row - stairPos[numStair][0]) + abs(col - stairPos[numStair][1]);
                }
            }
        }
    }
}

void dfs(int step) {
    if (step == 0)
        return;
    
    step--;
    for (int i = 0; i < 2; ++i) {
        stairNo[step] = i;
        dfs(step);
    }
}

void run() {
    for (int i = 0; i < numHuman; ++i) {
    }
}