#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    vector<int> seq;
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        set_sequentials();
        for (auto s : seq) {
            if (s > high) break;
            if (s >= low) ans.push_back(s);
        }
        return ans;
    }

    void set_sequentials() {
        for (int digit = 2; digit < 10; ++digit) {
            int begin = set_begin(digit);
            int upper_bound = set_upbnd(digit);
            int gap = set_gap(digit);
            while (begin <= upper_bound) {
                seq.push_back(begin);
                begin += gap;
            }
        }
    }

    int set_begin(int digit) {
        int begin = 0;
        for (int add = 1; add <= digit; ++add) {
            begin = begin * 10 + add;
        }
        return begin;
    }

    int set_upbnd(int digit){
        int upbnd = 0;
        int mul = 1;
        for (int add = 9; add > 9 - digit; --add) {
            upbnd += add * mul;
            mul *= 10;
        }
        return upbnd;
    }

    int set_gap(int digit) {
        int gap = 0;
        while (digit > 0) {
            gap = gap * 10 + 1;
            --digit;
        }
        return gap;
    }
};