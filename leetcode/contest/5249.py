from collections import stac

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        for letter in s:
            if letter != ")":
                stack.append(letter)
            if letter == ')':
                while True:
                    last = stack.pop



if __name__ == "__main__":
    input = "))(("

    print(Solution().minRemoveToMakeValid(input))