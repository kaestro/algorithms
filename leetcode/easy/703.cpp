#include <queue>
#include <vector>
#include <functional>

using namespace std;

class KthLargest {
 private:
    priority_queue<int, vector<int>, greater<int>> kLargests;
    int k;
public:
    KthLargest(int k, vector<int>& nums):k(k) {
        auto it = nums.begin();
        for (auto i = 0; it != nums.end() && i < k; ++i)
            kLargests.push(*(it++));

        while (it != nums.end())
        {
            kLargests.push(*(it++));
            kLargests.pop();
        }
    }
    
    int add(int val) {
        kLargests.push(val);
        if (kLargests.size() > k)
            kLargests.pop();
        return kLargests.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */