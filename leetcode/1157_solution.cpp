#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

typedef vector< int > vi;

class MajorityChecker {
 public:
     explicit MajorityChecker(const vector< int >& arr) {
         for (auto i = 0; i < arr.size(); ++i) {
             idx[arr[i]].push_back(i);
         }
     }

     int query(int left, int right, int threshold) {
         for (auto& i : idx) {
             if (i.second.size() < threshold) continue;
             auto it1 = lower_bound(begin(i.second), end(i.second), left);
             auto it2 = upper_bound(begin(i.second), end(i.second), right);
             if (it2 - it1 >= threshold) return i.first;
         }
          return -1;
     }

 private:
    map< int, vi > idx;
};


/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

int main() {
    vector<int> input = {1, 1, 2, 2, 1, 1};
    MajorityChecker mc(input);
    vector< vector< int > > queries = {
        {0, 5, 4}, {0, 3, 3}, {2, 3, 2}
    };
    for (auto query : queries) {
        cout << mc.query(query[0], query[1], query[2]) << endl;
    }
}


