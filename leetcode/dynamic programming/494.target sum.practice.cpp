#include <vector>

// subsub_i_j is number of cases that
// 1st to ith element subsum equals j.
// ex) subsum_i_j[3][5] means subsum of 
// 1,2,3 element sums to 5
// [1,4,5] => subsum_i_j[3][5] = 2 ; // [1, 4], [5]
class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int S) {
        std::vector<std::vector<int>> subsum_i_j;
        subsum_i_j.resize(nums.size()+1);
        for (size_t i = 0; i < subsum_i_j.size(); ++i) {
            subsum_i_j[i].resize(S+1);
            subsum_i_j[i][0] = 1;
        }

        for (size_t i = 1; i < subsum_i_j.size(); ++i) {
            for (size_t j = nums[i-1]; j <= S; ++j) {
                subsum_i_j[i][j] = subsum_i_j[i-1][j] + subsum_i_j[i-1][j - nums[i-1]];
            }
        }

        return subsum_i_j[subsum_i_j.size()-1][S];
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1,1,1,1,1};
    int sum = 3;
    auto ans = s.findTargetSumWays(nums, sum);

    return 0;
}