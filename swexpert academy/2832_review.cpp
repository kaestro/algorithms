#include <map>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Bacteria {
 public:
    int number;
    int dir_idx;

    Bacteria(int number, int dir_idx):number(number), dir_idx(dir_idx)
    {}
};

class Position {
 public:
    int row, col;

    Position(int row, int col):row(row), col(col)
    {}

    Position operator +(const Position& rhs) const{
        return Position(this->row + rhs.row, this->col + rhs.col);
    }

    bool operator <(const Position& rhs) const{
        if (this->row < rhs.row) return true;
        if (this->row == rhs.row && this->col < rhs.col) return true;
        return false;
    }
};

typedef vector< Bacteria > vb;

const vector< Position > direction = {
    Position(-1, 0), Position(1, 0), Position(0, -1), Position(0, 1)
};

int answer;
map< Position, vb > swarm, copySwarm;
int cellSize, numRep, bacteriaNumber;

void reset();
void read();
void solution();

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

void reset() {
    swarm.clear();
    answer = 0;
    cellSize = numRep = bacteriaNumber = 0;
}

void read() {
    cin >> cellSize >> numRep >> bacteriaNumber;
    int row, col;
    int number, dir_idx;
    for (auto n = 0; n < bacteriaNumber; ++n) {
        cin >> row >> col >> number >> dir_idx;
        swarm[Position(row,col)].push_back(Bacteria(number, dir_idx - 1));
    }
}

inline bool isBoundary(const Position& pos){
    return pos.row == 0 || pos.row == cellSize - 1 || pos.col == 0 || pos.col == cellSize - 1;
}

void revert(int& dir_idx){
    switch(dir_idx) {
        case 0: dir_idx = 1; break;
        case 1: dir_idx = 0; break;
        case 2: dir_idx = 3; break;
        case 3: dir_idx = 2; break;
        default: cout << "direction error" << endl;
    }
}

void move() {
    copySwarm.clear();
    for (auto it = swarm.begin(); it != swarm.end(); ++it) {
        Position next = it->first + direction[it->second[0].dir_idx];
        if(isBoundary(next)){
            revert(it->second[0].dir_idx);
            it->second[0].number /= 2;
        }
        copySwarm[next].push_back(it->second[0]);
    }
    swarm.clear();
    swarm = copySwarm;
}

void collect() {
    int totalNumber, maxNumber, maxDir;
    for (auto it = swarm.begin(); it != swarm.end(); ++it) {
        if (it->second.size() > 1) {
            totalNumber = maxNumber = 0;
            maxDir = -1;
            for (auto bit = it->second.begin(); bit != it->second.end(); ++bit) {
                totalNumber += bit->number;
                if (bit->number > maxNumber) {
                    maxNumber = bit->number;
                    maxDir = bit->dir_idx;
                }
            }
            it->second.clear();
            it->second.push_back(Bacteria(totalNumber, maxDir));
        }
    }
}

void rep() {
    for (auto n = 0; n < numRep; ++n) {
        move();
        collect();
    }
}

void count() {
    for (auto it = swarm.begin(); it != swarm.end(); ++it) {
        answer += it->second[0].number;
    }
}

void solution() {
    rep();
    count();
}



