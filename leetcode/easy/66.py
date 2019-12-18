from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ans_int = 0
        for val in digits:
            ans_int = ans_int * 10 + val
        ans_int += 1
        ans = []
        while ans_int > 0:
            ans.append(ans_int % 10)
            ans_int //= 10
        return ans[::-1]
    
if __name__ == "__main__":
    lst = [1,2,3]
    ans = Solution().plusOne(lst)
    print(ans)