#include <map>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Bacteria {
 public:
     Bacteria(int number, int dir_idx) {
         this->number = number;
         this->dir_idx = dir_idx;
     }
     int number;
     int dir_idx;
};

class Position {
 public:
     Position(int row, int col) {
         this->row = row;
         this->col = col;
     }
     bool operator < (const Position& rhs) const {
         if (this->row < rhs.row) return true;
         if (this->row == rhs.row && this->col < rhs.col) return true;
         return false;
     }
     Position operator + (const Position& rhs) const {
         return Position(this->row + rhs.row, this->col + rhs.col);
     }
     int row;
     int col;
};

const vector< Position > direction = {
    Position(-1, 0), Position(1, 0), Position(0, -1), Position(0, 1)
};


map< Position, vector< Bacteria > > swarm;
int answer;
int swarmSize, numBacteria, numRep;


void read();
void reset();
void showSwarm();
void solution();

int main() {
    int T;
    freopen("2832.txt", "r", stdin);
    cin >> T;
    for (auto testcase = 1; testcase <= T; ++testcase) {
        reset();
        read();
        //showSwarm();
        solution();
        //showSwarm();
        cout << "#" << testcase << " " << answer << endl;
    }
}

void reset() {
    swarm.clear();
    answer = 0;
    numBacteria = 0, swarmSize = 0;
}

void read() {
    cin >> swarmSize >> numRep >> numBacteria;
    int number, dir_idx;
    int row, col;
    for (auto i = 0; i < numBacteria; ++i) {
        cin >> row >> col >> number >> dir_idx;
        answer += number;
        swarm[Position(row, col)].push_back(Bacteria(number, dir_idx - 1));
    }
}

void showSwarm() {
    for (auto vb = swarm.begin(); vb != swarm.end(); ++vb) {
        cout << "(" << vb->first.row << "," << vb->first.col << "): ";
        for (auto it = vb->second.begin(); it != vb->second.end(); ++it) {
            cout << "[" << it->number << "," << it->dir_idx + 1 << "]";
        }
        cout << endl;
    }
    cout << endl;
}

bool isBoundary(const Position& input) {
    return input.row == 0 || input.row == swarmSize - 1 || input.col == 0 || input.col == swarmSize - 1;
}

void revert(int& idx) {
    switch(idx){
        case 0: idx = 1; break;
        case 1: idx = 0; break;
        case 2: idx = 3; break;
        case 3: idx = 2; break;
        default: cout << "Error at idx" << endl; break;
    }
}


void collect() {
    for (auto& cell : swarm) {
        if (cell.second.size() > 1) {
            int sum = 0;
            int maxNumber = 0;
            int maxDir = -1;
            for (auto it = cell.second.begin(); it != cell.second.end(); ++it) {
                sum += it->number;
                if (it->number > maxNumber) {
                    maxNumber = it->number;
                    maxDir = it->dir_idx;
                }
            }
            cell.second.clear();
            cell.second.push_back(Bacteria(sum, maxDir));
        }
    }
}

void move() {
    for (auto times = 0; times < numRep; ++times) {
        map< Position, vector< Bacteria > > copy;
        for (auto& cell : swarm) {
            Position next = cell.first + direction[cell.second[0].dir_idx];
            if (isBoundary(next)) {
                revert(cell.second[0].dir_idx);
                int diff = cell.second[0].number - cell.second[0].number / 2;
                answer -= diff;
                cell.second[0].number /= 2;
            }
            copy[next].push_back(cell.second[0]);
        }
        swarm.clear();
        swarm = copy;
        //showSwarm();
        collect();
        //showSwarm();
    }
}

void solution() {
    move();
}


