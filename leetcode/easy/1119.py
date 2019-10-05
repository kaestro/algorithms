class Solution:
    def removeVowels(self, S: str) -> str:
        ans = ""
        for c in S:
            if c not in ['a', 'e', 'i', 'o', 'u']:
               ans += c
        return ans
    
    def removeVowels2(self, S: str) -> str:
        return "".join(c for c in S if c not in "aeiou")