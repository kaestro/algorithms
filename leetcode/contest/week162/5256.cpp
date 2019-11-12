#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> answer;
        answer.resize(2);
        int cs_length = colsum.size();
        for (int r = 0; r < 2; ++r) {
            answer[r].resize(cs_length);
        }
        for (int i = 0; i < cs_length; ++i) {
            if (colsum[i] == 2) {
                if (upper > 0 && lower > 0) {
                    answer[0][i] = 1; answer[1][i] = 1;
                    --upper;
                    --lower;
                } else {
                    return {};
                }
            }
        }
        for (int i = 0; i < cs_length; ++i) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    --upper;
                    answer[0][i] = 1;
                } else if (lower > 0) {
                    --lower;
                    answer[1][i] = 1;
                } else {
                    return {};
                }
            }
        }
        if (upper + lower == 0) return answer;
        else return {};
    }
};