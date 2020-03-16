#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> max_speeds;
    vector<pii> eff_speeds;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        for (int i = 0; i < n; ++i) {
            eff_speeds.push_back({efficiency[i], speed[i]});
        }
        sort(begin(eff_speeds), end(eff_speeds));

        long long sum = 0, res = 0;
        for (int i = n-1; i >= 0; --i) {
            sum += eff_speeds[i].second;
            max_speeds.push(eff_speeds[i].second);
            // this gets turned on when it its k. This may improve the performance
            // wrong idea for this problem wants to find the maximum performance atmost k people
            if (max_speeds.size() > k) {
                sum -= max_speeds.top();
                max_speeds.pop();
            }
            res = max(res, sum * eff_speeds[i].first);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 2, n = 6;
    cout << S.maxPerformance(n, speed, efficiency, k) << endl;
    return 0;
}