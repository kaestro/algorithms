#include <string>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define pillar second;
#define beam first;

class frame;

using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using bb = pair<bool, bool>;
using myMap = map<ii, frame>; // {col, row}, {beamExists, pillarExists}

myMap* process_orders(vvi& build_frame);

class frame {
 public:
    bool exist_beam;
    bool exist_pillar;
    frame():exist_beam(false), exist_pillar(false) {}
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
    bool is_destructable_pillar(int row, int col);
    bool is_destructable_beam(int row, int col);
    ~BuildFrame() {
        delete structure;
    }
};

vvi* convertMapToVector (myMap* build_frame_map);

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>>* answer;
    myMap* build_frame_map = process_orders(build_frame);
    answer = convertMapToVector(build_frame_map);

    delete build_frame_map;
    return *answer;
}

int main() {
    vector<vvi> build_frames {
        { 
            {1,0,0,1}, {1,1,1,1}, {2,1,0,1}, {2,2,1,1},
            {5,0,0,1}, {5,1,0,1}, {4,2,1,1}, {3,2,1,1} 
        },
        { 
            {0,0,0,1}, {3,0,0,1}, {0,1,1,1}, {2,1,1,1}, {1,1,1,1},
            {1,1,1,0} },
        {
            {0,0,0,1}, {4,0,0,1}, {0,1,1,1}, {3,1,1,1},
            {1,0,0,1},{1,1,1,1}, {2,1,1,1},
            {1,0,0,0}, {2,1,1,0}
        },
        {
            {0,0,0,1}, {4,0,0,1}, {0,1,1,1}, {3,1,1,1},
            {1,0,0,1}, {1,1,1,1}, {2,1,1,1}, {2,1,0,1},
            {2,1,1,0}
        },
        {
            {0,0,0,1}, {4,0,0,1}, {0,1,1,1}, {3,1,1,1},
            {1,0,0,1}, {1,1,1,1}, {2,1,1,1}, {3,1,0,1},
            {2,1,1,0}
        }  
    };
    solution(5, build_frames[2]);
    // solution(5, build_frames[3]);
    solution(5, build_frames[4]);
}

vvi* convertMapToVector(myMap* build_frame_map) {
    vvi* result = new vvi;
    for (auto& frame : *build_frame_map) 
    {
        if (frame.second.exist_pillar)
            (*result).push_back({frame.first.first, frame.first.second, 0});
        if (frame.second.exist_beam)
            (*result).push_back({frame.first.first, frame.first.second, 1});
    }
    return result;
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
    if (
        row == 0 ||
        (*structure)[{col, row - 1}].exist_pillar ||
        (*structure)[{col -1, row}].exist_beam || (*structure)[{col + 1, row}].exist_beam 
    )
        (*this->structure)[position].exist_pillar = true;
}

void BuildFrame::install_beam(ii position) {
    int col = position.first, row = position.second;
    if (row == 0) return;
    else if (exists_pillar_under(row, col)) (*structure)[position].exist_beam = true;
    else if (exists_beam_both_end(row, col)) (*structure)[position].exist_beam = true;
}

bool BuildFrame::exists_pillar_under(int row, int col) {
    return (*structure)[{col, row -1}].exist_pillar || (*structure)[{col + 1, row - 1}].exist_pillar;
}

bool BuildFrame::exists_beam_both_end(int row, int col) {
    return (*structure)[{col -1, row}].exist_beam && (*structure)[{col + 1, row}].exist_beam;
}

void BuildFrame::destruct_pillar(ii position) {
    if (is_destructable_pillar(position.second, position.first))
        (*structure)[position].exist_pillar = false;
}

bool BuildFrame::is_destructable_pillar(int row, int col) {
    vector<bool> flags = {
        (*structure)[{col, row + 1}].exist_pillar,
        (*structure)[{col - 1, row + 1}].exist_beam,
        (*structure)[{col, row + 1}].exist_beam
    }; // pillar, left beam, right beam

    if (flags == vector<bool>{false, false, false}) return true;

    if (flags == vector<bool>{true, false, false}) return false;

    if (flags == vector<bool>{true, true, false} || flags == vector<bool>{false, true, false})
        if (!(*structure)[{col - 1, row}].exist_pillar)
            return false;
    
    if (flags == vector<bool>{true, false, true} || flags == vector<bool>{false, false, true})
        if (!(*structure)[{col + 1, row}].exist_pillar)
            return false;
    
    if (flags == vector<bool>{true, true, true} || flags == vector<bool>{false, true, true})
        if (!(*structure)[{col - 1, row}].exist_pillar && !(*structure)[{col - 2, row + 1}].exist_beam ||
            !(*structure)[{col + 1, row}].exist_pillar && !(*structure)[{col + 1, row + 1}].exist_beam )
            return false;

    return true;
}

void BuildFrame::destruct_beam(ii position) {
    if (is_destructable_beam(position.second, position.first))
        (*structure)[position].exist_beam = false;
}

bool BuildFrame::is_destructable_beam(int row, int col) {
    if ((*structure)[{col - 1, row}].exist_beam && !exists_pillar_under(row, col - 1)) return false;
    if ((*structure)[{col + 1, row}].exist_beam && !exists_pillar_under(row, col + 1)) return false;
    if ((*structure)[{col, row}].exist_pillar && !(*structure)[{col, row - 1}].exist_pillar
        && !(*structure)[{col - 1, row}].exist_beam
    ) return false;
    if ((*structure)[{col + 1, row}].exist_pillar && !(*structure)[{col + 1, row}].exist_beam
        && !(*structure)[{col + 1, row - 1}].exist_pillar
    ) return false;
    return true;
}