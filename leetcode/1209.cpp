#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

typedef pair< int, int > ii;
typedef vector< ii > vii;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector< pair< char, int > > sTopair;
        int length = s.length();
        char c = s[0];
        int num = 0;
        for (int i = 0; i < length; ++i) {
            if (c == s[i]) {
                num++;
            } else {
                sTopair.push_back({c, num});
                c = s[i];
                num = 1;
            }
        }
        sTopair.push_back({c,num});

        auto it = sTopair.begin();
        while (it != sTopair.end()) {
            it->second %= k;
            if (it->second == 0) {
                it = sTopair.erase(it);
                if (it == sTopair.begin()) continue;
                auto bit = it - 1;
                if (bit->first == it->first) {
                    bit->second += it->second;
                    sTopair.erase(it);
                    it = bit;
                }
            } else {
                it++;
            }
        }
        string result;
        for (auto p : sTopair) {
            for (int i = 0; i < p.second; ++i) {
                result += p.first;
            }
        }
        return result;
    }
};

int main() {
    string s;
    int k;
    Solution temp;
    cin >> s >> k;
    cout << temp.removeDuplicates(s, k) << endl;
}