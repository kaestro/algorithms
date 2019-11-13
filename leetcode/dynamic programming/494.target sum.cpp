#include <vector>
#include <numeric>


class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int S) {
        int sum_num = std::accumulate(nums.begin(), nums.end(), 0);
        int target = sum_num - S;
        if (target % 2 || target < 0) return 0;

        target /= 2;
        std::vector<int> subsum_index(target+1, 0);
        subsum_index[0] = 1;
        for (auto num : nums) {
            if (num > target) continue;
            /*
            for (size_t i = num; i < target+1; ++i) {
                temp[i] += subsum_index[i-num];
            }
            subsum_index = temp;
            */
            // need to loop from top. or, it will add the one that shouldn't.
            // ex) 2번째까지 수 subsum = 5 개수가 3개라 하자.
            // 3번째까지 수 subsum = 7, 9이 되는 경우의 수 세려고 할 때 아래에서부터
            // count할 경우 subsum = 7에 += 3가지 경우의 수를 한 상태에서
            // subsum = 9에 subsum 7의 경우의 수를 더하므로, +3이 두 번 더해지게 된다.
            for (int i = target; i >= num; --i) {
                subsum_index[i] += subsum_index[i - num];
            }
        }
        return subsum_index[target];
    }
};

int main() {
    std::vector<int> nums = {1,1,1,1,1,2};
    int S = 3;
    Solution s;
    nums = {1,0};
    S = 1;
    auto ans = s.findTargetSumWays(nums, S);
    return 0;
}