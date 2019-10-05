#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int INACTIVE = 0;
const int ACTIVE = 1;
const int DEAD = 2;

class StemCell {
 public:
    int lifetime, healthPoint;
    int active;

    StemCell(int lt, int hp):lifetime(lt), healthPoint(hp), active(INACTIVE)
    {}

    StemCell():lifetime(0), healthPoint(0), active(INACTIVE)
    {}

    void increment(){
        if (active == DEAD) 
            return;
        lifetime++;
        if (lifetime >= 2 * healthPoint)
            active = DEAD;
        else if (lifetime >= healthPoint)
            active = ACTIVE;
    }
};

typedef pair< int, int > ii;
typedef map< ii, StemCell > myMap;
typedef vector< int > vi;
typedef queue< ii > myQueue;

const vector< ii > direction = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

map< ii, StemCell > simulation;
myQueue q[11];
int timeLimit;

void reset(){
    simulation.clear();
    timeLimit = 0;
    for (int i = 0; i < 11; ++i)
        q[i] = myQueue();
}

void read();
void simulate();
int answer();
void breed(const ii& pos);

int main() {
    int T;
    freopen("5653.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <=T; ++testcase) {
        reset();
        read();
        simulate();
        cout << "#" << testcase << " " << answer() << endl;
    }
}

void read(){
    int rowSize, colSize;
    cin >> rowSize >> colSize >> timeLimit;
    for (int row = 0; row < rowSize; ++row) {
        for (int col = 0; col < colSize; ++col) {
            int hp;
            cin >> hp;
            if (hp == 0) continue;
            StemCell temp(0, hp);
            simulation[{row,col}] = temp;
            q[hp].push({row, col});
        }
    }
}

void simulate() {
    for (int t = 0; t < timeLimit; ++t) {
        for (int i = 10; i >= 1; --i) {
            int qSize = q[i].size();
            for (int j = 0; j < qSize; ++j) {
                ii pos = q[i].front();
                q[i].pop();
                if(simulation[pos].lifetime == simulation[pos].healthPoint)
                    breed(pos);

                simulation[pos].increment();

                if (simulation[pos].active != DEAD)
                    q[i].push(pos);
            }
        }
    }
}

void breed(const ii& pos) {
    ii npos;
    int hp = simulation[pos].healthPoint;
    for (int d = 0; d < 4; ++d) {
        npos.first = pos.first + direction[d].first;
        npos.second = pos.second + direction[d].second;

        myMap::iterator it = simulation.find(npos);
        if (it == simulation.end()) {
            simulation[npos] = StemCell(0, hp);
            q[hp].push(npos);
        }
    }
}

int answer() {
    int sum = 0;
    for (int i = 1; i < 11; ++i) {
        sum += q[i].size();
    }
    return sum;
}