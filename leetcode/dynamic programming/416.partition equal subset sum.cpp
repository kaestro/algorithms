#include <vector>
#include <bitset>
#include <numeric>

const int max_int = 100;
const int max_arr = 200;

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return 0;

        std::bitset<max_int * max_arr / 2 + 1> bs(1); 
        for (auto num : nums) {
            bs |= bs << num;
        }
        return bs[sum/2];
    }
};