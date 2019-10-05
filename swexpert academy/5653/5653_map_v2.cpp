#include <map>
#include <vector>
#include <iostream>
#include <cstdio>

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

const vector< ii > direction = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

myMap simulation;
myMap bred;
int timeLimit;

void reset(){
    simulation.clear();
    timeLimit = 0;
}

void read();
void simulate();
int answer();
void breed(const ii& pos, const StemCell& sc);

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
        }
    }
}

void simulate() {
    for (int i = 0; i < timeLimit; ++i) {
        bred.clear();
        for (myMap::iterator it = simulation.begin(); it != simulation.end();++it) {
            if (it->second.active == ACTIVE) {
                breed(it->first, it->second);
            }
            it->second.increment();
        }

        for (myMap::iterator it = bred.begin(); it != bred.end(); ++it) {
            simulation.insert(*it);
        }
    }
}

void breed(const ii& pos, const StemCell& st) {
    for (int d = 0; d < direction.size(); ++d) {
        ii nextPos = { pos.first + direction[d].first, pos.second + direction[d].second };
        myMap::iterator it = simulation.find(nextPos);
        if (it == simulation.end()) {
            myMap::iterator bit = bred.find(nextPos);
            if (bit == bred.end()) {
                bred[nextPos] = StemCell(0, st.healthPoint);
            } else if (bit->second.healthPoint < st.healthPoint) {
                bit->second.healthPoint = st.healthPoint;
            }
        }
    }
}

int answer() {
    int sum = 0;
    for (myMap::iterator it = simulation.begin(); it != simulation.end(); ++it) {
        if (it->second.active != DEAD)
            sum++;
    }
    return sum;
}