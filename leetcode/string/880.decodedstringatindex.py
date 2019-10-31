class Solution:
    def decodeAtIndex(self, input: str, K: int) -> str:
        # min substring of answer length which is over K
        substr_length = 0
        for last_index, letter in enumerate(input):
            if letter in "23456789":
                substr_length *= int(letter)
            else:
                substr_length += 1
            if K <= substr_length:
                break
        
        for j in range(last_index, -1, -1):
            letter = input[j]
            if letter in "23456789":
                substr_length =int(substr_length/int(letter))
                K %= substr_length
            else:
                if K == 0 or K == substr_length:
                    return letter
                else:
                    substr_length -= 1


if __name__ == "__main__":
    print(Solution().decodeAtIndex("ha22", 5))