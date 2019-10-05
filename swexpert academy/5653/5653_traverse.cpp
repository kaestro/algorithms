#include <unordered_map>
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
    bool traversed;

    StemCell(int lt, int hp):lifetime(lt), healthPoint(hp), active(INACTIVE), traversed(true)
    {}

    StemCell():lifetime(0), healthPoint(0), active(INACTIVE), traversed(true)
    {}

    void increment(){
        if (active == DEAD) 
            return;
        lifetime++;
        if (lifetime >= 2 * healthPoint)
            active = DEAD;
        else if (lifetime >= healthPoint)
            active = ACTIVE;
        
        traversed = false;
    }
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &pair) const {
        return hash<T1>()(pair.first) & hash<T2>()(pair.second);
    }
};

typedef pair< int, int > ii;
typedef unordered_map< ii, StemCell, pair_hash > myMap;
typedef vector< int > vi;

const vector< ii > direction = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

unordered_map< ii, StemCell, pair_hash > simulation;
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
    //freopen("5653.txt", "r", stdin);
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
        for (myMap::iterator it = simulation.begin(); it != simulation.end();++it) {
            if (it->second.active == DEAD || it->second.lifetime == -1) continue;
            if (it->second.traversed) continue;
            if (it->second.active == ACTIVE) {
                const ii& pos = it->first;
                const StemCell& sc = it->second;
                breed(pos, sc);
                it = simulation.find(pos);
                it->second.traversed = true;
                it = simulation.begin();
            }
        }

        for (myMap::iterator it = simulation.begin(); it != simulation.end(); ++it) {
            it->second.increment();
        }
    }
}

void breed(const ii& pos, const StemCell& st) {
    for (int d = 0; d < direction.size(); ++d) {
        ii nextPos = { pos.first + direction[d].first, pos.second + direction[d].second };
        myMap::iterator it = simulation.find(nextPos);
        if (it == simulation.end()) {
            simulation[nextPos] = StemCell(-1, st.healthPoint);
        } else if (it->second.lifetime == -1){
            if (it->second.healthPoint < st.healthPoint) {
                it->second.healthPoint = st.healthPoint;
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