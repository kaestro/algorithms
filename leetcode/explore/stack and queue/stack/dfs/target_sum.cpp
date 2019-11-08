#include <vector>

class Solution {
 private:
    size_t depth;
    int target_sum;
    std::vector<int> input;
public:
    int findTargetSumWays(std::vector<int>& nums, int S) {
        depth = nums.size();
        target_sum = S;
        input = nums;
        std::vector<int> root;
        return dfs(root);
    }

    int dfs(std::vector<int>& permutation) {
        int ans = 0;
        int p_size = permutation.size();
        int sign = -1;
        if (p_size == depth) {
            int sum = 0;
            for (auto num : permutation) {
                sum += num;
            }
            if (target_sum == sum) {
                return 1;
            } else {
                return 0;
            }
        }
        for (int i = 0; i < 2; ++i) {
            sign *= -1;
            permutation.push_back(sign * input[p_size]);
            ans += dfs(permutation);
            permutation.pop_back();
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1,1,1,1,1};
    int target_sum = 3;
    int ans = s.findTargetSumWays(nums, target_sum);
    return 0;
}