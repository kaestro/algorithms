#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> bfs;

        string init = "0000";
        if (dds.find(init) != dds.end()) return -1;
        visited.insert(init);
        bfs.push(init);
        int shortest_length = 0;

        while (!bfs.empty())
        {
            int prev_size = bfs.size();
            for (size_t i = 0; i < prev_size; ++i) {
                string cur = bfs.front(); bfs.pop();
                vector<string> nbrs = move(nbrStrs(cur));
                for (auto s : nbrs) {
                    if (s == target)
                        return ++shortest_length;
                    if (visited.find(s) != visited.end()) continue;
                    if (dds.find(s) == dds.end()) {
                        bfs.push(s);
                        visited.insert(s);
                    }
                }
            }
            ++shortest_length;
        }

        return -1;
    }

    vector<string> nbrStrs(string key) {
        vector<string> result;
        for (size_t i = 0; i < 4; ++i) {
            string temp = key;
            temp[i] = (key[i] - '0' + 1) % 10 + '0';
            result.push_back(temp);
            temp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> input = {
        "0201", "0101", "0102", "1212", "2002"
    };
    s.openLock(input, "0202");

    return 0;
}