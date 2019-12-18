import collections

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        left = collections.Counter(ransomNote)
        right = collections.Counter(magazine)
        ans = left - right
        return not ans
    
if __name__ == "__main__":
    ransomNote = "aa"
    magazine = "aab"
    print(Solution().canConstruct(ransomNote, magazine))