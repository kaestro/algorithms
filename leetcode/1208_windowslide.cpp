#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.length();
        vector< int > diff(length);
        for (int i = 0; i < length; ++i) {
            diff[i] = abs(s[i] - t[i]);
        }

        int curCost = maxCost;
        int left = 0;
        int right = 0;
        int maxVal = 0;
        for (; right < length; ++right) {
            curCost -= diff[right];
            if (curCost < 0) {
                curCost += diff[left++];
            }
            maxVal = max(maxVal, right + 1 - left);
        }
        return maxVal;
    }
};

int main() {
    string s, t;
    int maxCost;

    cin >> s >> t >> maxCost;

    Solution temp;

    cout << temp.equalSubstring(s, t, maxCost) << endl;

    return 0;
}