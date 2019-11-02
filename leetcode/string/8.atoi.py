class Solution:


    def __init__(self):
        self.alphabet = "abcdefghijklmnopqrstuvwxyz" \
            + "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        self.min_limit = - 2**31
        self.max_limit = -(self.min_limit) - 1


    def myAtoi(self, input: str) -> int:
        min_idx = 0
        while min_idx < len(input):
            if input[min_idx] == ' ':
                min_idx += 1
            else:
                break
        
        if min_idx == len(input):
            return 0
        if input[min_idx] in self.alphabet:
            return 0
        before_conversion = input[min_idx:].split(' ')[0]

        min_idx = 0
        is_minus = False
        if before_conversion[min_idx] == '-':
            is_minus = True
            min_idx += 1
        
        while min_idx < len(before_conversion):
            if before_conversion[min_idx] == '.':
                break
            else:
                min_idx += 1
        
        if min_idx == 0 or (min_idx == 1 and is_minus):
            return 0
        
        if min_idx != len(before_conversion):
            result = int(before_conversion[:min_idx])
        else:
            result = int(before_conversion)

        if result < self.min_limit: return self.min_limit

        if result > self.max_limit: return self.max_limit

        return result