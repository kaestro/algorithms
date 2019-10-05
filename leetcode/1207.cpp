#include <vector>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map< int, int > temp;
        for (auto a : arr) {
            if (temp.find(a) == temp.end()) {
                temp[a] = 1;
            } else {
                temp[a]++;
            }
        }
        set< int > st;
        for (auto m : temp) {
            st.insert(m.second);
        }
        return temp.size() == st.size();
    }
};
