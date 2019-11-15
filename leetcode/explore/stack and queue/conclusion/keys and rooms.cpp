#include <vector>
#include <queue>
#include <bitset>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

const int max_key = 1000;

class Solution {
public:
    bool canVisitAllRooms(vvi& rooms) {
        std::queue<int> room_q;
        //std::vector<bool> visited(rooms.size());
        std::bitset<max_key> visited(1);
        std::bitset<max_key> all_visited(0);
        for (int i = 0; i < rooms.size(); ++i) {
            all_visited <<= 1;
            all_visited |= 1;
        }

        for (auto key : rooms[0]) {
            visited[key] = true;
            room_q.push(key);
        }

        while (!room_q.empty()) {
            size_t room_left = room_q.size();
            for (size_t i = 0; i < room_left; ++i) {
                int key = room_q.front(); room_q.pop();
                for (size_t j = 0; j < rooms[key].size(); ++j) {
                    int next_key = rooms[key][j];
                    if (visited[next_key]) continue;
                    visited[next_key] = true;
                    room_q.push(next_key);
                }
            }
            if (visited == all_visited) return true;
        }
        return visited == all_visited;
    }
};

int main() {
    Solution s;
    vvi input = {
        {1},{2},{3},{}
    };
    input = {
        {1,3},
        {3,0,1},
        {2},
        {0}
    };
    auto ans = s.canVisitAllRooms(input);
    return 0;
}