from typing import List

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        res = {}
        for num in arr:
            res[num] = res[num - difference] + 1 if (num - difference) in res else 1

        return max(res.values())



if __name__ == "__main__":
    arr = [1,2,3,4]
    difference = 1
    arr2 = [1,5,7,8,5,3,4,2,1]
    difference = -2
    #print(Solution().longestSubsequence(arr, difference))
    print(Solution().longestSubsequence(arr2, difference))