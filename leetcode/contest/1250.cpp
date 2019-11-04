#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) {
            if (nums[0] == 1) return true;
            else return false;
        }

        int comp = gcd(nums[0], nums[1]);

        if (comp == 1) return true;

        for (auto i = 2; i < nums.size(); ++i) {
            comp = gcd(comp, nums[i]);
            if (comp == 1) return true;
        }
        return false;
    }

    int gcd(int left, int right) {
        if (left < right) swap(left, right);
        int remainder = right;
        right = left;
        do {
            left = right;
            right = remainder;
            remainder = (left % right);
        } while (remainder != 0 && remainder != 1);

        if (remainder == 1) {
            return 1;
        } else {
            return right;
        }
    }
};

int main() {
    Solution s;
    //vector<int> nums = {12, 5, 7, 23};
    //vector<int> nums = {29, 6, 10};
    //vector<int> nums = {3, 6};
    vector<int>nums = {15,15,15,18,35,35,42,42,7};
    if (s.isGoodArray(nums))
        cout << "is a good array" << endl;

    return 0;
}