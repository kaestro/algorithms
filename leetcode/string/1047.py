class Solution:
    def removeDuplicates(self, S: str) -> str:
        res = []
        for letter in S:
            if res and res[-1] == letter:
                res.pop()
            else:
                res.append(letter)
        return ''.join(res)
