#include <vector>
#include <algorithm>

using namespace std;

int findParent(vector<int>& parent, int index) {
    if (parent[index] != index) {
        parent[index] = findParent(parent, parent[index]);
    }
    return parent[index];
}

void unionChild(vector<int>& parent, int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);
    parent[yroot] = xroot;
}

bool allFriends(vector<int>& parent) {
    int N = parent.size();
    int root = findParent(parent, 0);
    for (int i = 1; i < N; ++i) {
        if (findParent(parent, i) != root) {
            return false;
        }
    }
    return true;
}

bool compare(vector<int>& left, vector<int>& right) {
    return left[0] < right[0];
}

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        int size = logs.size();
        if (size < N - 1) return -1;
        sort(logs.begin(), logs.end(), compare);

        vector< int > parent(N);
        for (int i = 0; i < N; ++i)
            parent[i] = i;

        for (int i = 0; i < N - 2; ++i) {
            unionChild(parent, logs[i][1], logs[i][2]);
        }

        for (int i = N - 2; i < size; ++i) {
            unionChild(parent, logs[i][1], logs[i][2]);
            if (allFriends(parent))
                return logs[i][0];
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> logs = {
        {20190101, 0, 1}, {20190107, 2, 3}, {20190211, 1, 5}, {20190224,2,4}, {20190301,0,3}, {20190312,1,2}, {20190322,4,5}
    };
    Solution s;
    s.earliestAcq(logs, 6);
}