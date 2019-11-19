#include <vector>
#include <algorithm>

using vi = std::vector<int>;

class Solution {
public:
    int maxSumDivThree(vi& nums) {
        std::sort(nums.begin(), nums.end());
        int sum_val = 0;
        std::vector<int> min_1, min_2;
        for (auto num : nums) {
            sum_val += num;
            if (num % 3 == 1) {
                if (min_1.size() < 2) min_1.push_back(num);
            } else if (num % 3 == 2) {
                if (min_2.size() < 2) min_2.push_back(num);
            }
        }

        int cand_1 = -1, cand_2 = -1;
        int result;
        if (sum_val % 3 == 1) {
            if (min_1.size() > 0) {
                cand_1 = sum_val - min_1[0];
            }
            if (min_2.size() == 2) {
                cand_2 = sum_val - min_2[0] - min_2[1];
            }
            result = std::max(cand_1, cand_2);
        } else if (sum_val % 3 == 2) {
            if (min_2.size() > 0) {
                cand_1 = sum_val - min_2[0];
            }
            if (min_1.size() == 2) {
                cand_2 = sum_val - min_1[0] -min_1[1];
            }
            result = std::max(cand_1, cand_2);
        } else {
            result = sum_val;
        }
        return sum_val;
    }
};

int main() {
    vi nums = {3,6,1,5,8};
    Solution s;
    auto ans = s.maxSumDivThree(nums);
    return 0;
}