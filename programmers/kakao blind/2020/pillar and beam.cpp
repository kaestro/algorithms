#include <string>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define pillar second;
#define beam first;

using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using bb = pair<bool, bool>;
using myMap = map<ii, bb>; // {col, row}, {beamExists, pillarExists}

myMap* process_orders(vvi& build_frame);

class frame {
    bool exist_beam;
    bool exist_pillar;
};

class BuildFrame {
 private:
 public:
    myMap* structure;
    BuildFrame() {
        structure = new myMap();
    }
    void install_Pillar(ii position);
    void destruct_pillar(ii position);
    void install_beam(ii position);
    void destruct_beam(ii position);
    bool exists_pillar_under(int row, int col);
    bool exists_beam_both_end(int row, int col);
    bool is_destructable_pillar(ii position);
    bool is_destructable_beam(ii position);
    ~BuildFrame() {
        delete structure;
    }
};

vvi convertMapToVector (myMap* build_frame_map);

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    myMap* build_frame_map = process_orders(build_frame);
    answer = convertMapToVector(build_frame_map);

    return answer;
}

inline bool testPillar (int flag) {
    return flag == 0;
}

inline bool testConstructionOrder (int flag) {
    return flag == 1;
}

myMap* process_orders(vvi& build_frame) {
    BuildFrame* myStructure = new BuildFrame();
    for (auto& order : build_frame)
    {
        ii position = {order[0], order[1]};
        bool isPillar = testPillar(order[2]);
        bool isConstructionOrder = testConstructionOrder(order[3]);
        if (isPillar && isConstructionOrder) myStructure->install_Pillar(position);
        else if (isPillar && !isConstructionOrder) myStructure->destruct_pillar(position);
        else if (!isPillar && isConstructionOrder) myStructure->install_beam(position);
        else myStructure->destruct_beam(position);
    }
    return myStructure->structure;
}

void BuildFrame::install_Pillar(ii position) {
    int col = position.first, row = position.second;
    if (row == 0) (*this->structure)[position].second = true;
    else if ((*this->structure)[{col, row - 1}].second == true) (*this->structure)[position].second = true;
    else if ((*this->structure)[{col -1, row}].first == true ||
        (*this->structure)[{col, row}].first == true) (*this->structure)[position].second = true;
}

void BuildFrame::install_beam(ii position) {
    int col = position.first, row = position.second;
    if (row == 0) return;
    else if (exists_pillar_under(row, col)) (*this->structure)[position].first = true;
    else if (exists_beam_both_end(row, col)) (*this->structure)[position].first = true;
}

bool BuildFrame::exists_pillar_under(int row, int col) {
    return (*this->structure)[{col, row -1}].second;
}

bool BuildFrame::exists_beam_both_end(int row, int col) {
    return (*structure)[{col -1, row}].first && (*structure)[{col + 1, row}].first;
}

void BuildFrame::destruct_pillar(ii position) {
    if (is_destructable_pillar)
        (*structure)[position].second = false;
}

bool BuildFrame::is_destructable_pillar(ii position) {
    int row = position.second, col = position.first;
    if ((*structure)[{col -1, row + 1}].beam == true);
}