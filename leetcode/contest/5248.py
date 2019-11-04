from typing import List


class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        odd_indexes = []
        for i, num in enumerate(nums):
            if num % 2 == 1:
                odd_indexes.append(i)
        
        if len(odd_indexes) == 0:
            return 0
        
        odd_indexes.insert(0, -1)
        odd_indexes.append(len(nums))
        
        ans = 0

        for first_idx in range(0, len(odd_indexes) - k - 1):
            last_idx = first_idx + k + 1
            from_left = odd_indexes[first_idx+1] - odd_indexes[first_idx]
            from_right = odd_indexes[last_idx] - odd_indexes[last_idx-1]
            ans += from_left * from_right
        
        return ans


if __name__ == "__main__":
    nums = [1,1,2,1,1]
    k = 3
    print(Solution().numberOfSubarrays(nums,k))
