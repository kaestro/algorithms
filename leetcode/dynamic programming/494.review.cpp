#include <vector>
#include <numeric>


class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int S) {
        int num_sum = std::accumulate(nums.begin(), nums.end(), 0);
        num_sum -= S;
        if (num_sum % 2) return false;
        if (num_sum < 0) return false;

        num_sum /= 2;
        std::vector<int>sumways_target(num_sum + 1, 0);
        sumways_target[0] = 1;
        for (auto num : nums) {
            for (int i = num_sum; i >= num; --i) {
                sumways_target[i] += sumways_target[i - num];
            }
        }
        return sumways_target[num_sum];
    }
};