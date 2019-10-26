class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        result = []
        for word in words:
            result.append(word[::-1])
        return ' '.join(result)


if __name__ == "__main__":
    print(Solution().reverseWords("Let's take LeetCode contest"))