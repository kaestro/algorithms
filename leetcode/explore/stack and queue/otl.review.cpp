#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
private:
    const string starting_point = "0000";
    unordered_set<string> dds;
    unordered_set<string> visited;
    queue<string> bfs;
public:
    int openLock(vector<string>& deadends, string target) {
        dds = unordered_set<string>(deadends.begin(), deadends.end());
        int shortest_length = 0;

        if (dds.find(starting_point) != dds.end()) return -1;

        bfs.push(starting_point);
        while (!bfs.empty())
        {
            size_t prev_size = bfs.size();
            for (size_t i = 0; i < prev_size; ++i)
            {
                auto cur = bfs.front(); bfs.pop();
                visited.insert(cur);
                if (cur == target) return shortest_length;
                create_next_pts(cur);
            }
            ++shortest_length;
        }

        return -1;
    }

    void create_next_pts(string cur_pt) {
        string temp;
        for (size_t i = 0; i < 4; ++i)
        {
            for (int diff = -1; diff <= 1; diff += 2) {
                temp = cur_pt;
                temp[i] = ((cur_pt[i] - '0' + diff + 10) % 10) + '0';
                if (visited.find(temp) == visited.end() && dds.find(temp) == dds.end()) {
                    bfs.push(temp);
                    visited.insert(temp);// the key point. the point should be set visited when inserted
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<string> input = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    s.openLock(input, "8888");
}