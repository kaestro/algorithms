#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int target_int = stoi(target);
        bool visited[10000] = {false};
        for (auto dd : deadends) {
            visited[stoi(dd)] = true;
        }
        queue<int> bfs;
        bfs.push(0);
        int shortest_length = 0;

        while (!bfs.empty())
        {
            size_t bfs_size = bfs.size();
            for (size_t i = 0; i < bfs_size; ++i)
            {
                int cur_pt = bfs.front(); bfs.pop();
                if (cur_pt == target_int) {
                    return shortest_length;
                }
                if (visited[cur_pt]) continue;
                visited[cur_pt] = true;
                for (int mask = 1; mask <= 1000; mask *= 10)
                {
                    for (int diff = 1; diff <= 9; diff += 8) {
                        int next = (cur_pt + ((cur_pt/mask + diff) % 10 - (cur_pt/mask) % 10) * mask);
                        bfs.push(next);
                    }
                }
            }
            ++shortest_length;
        }
        return -1;
    }
};