class Solution:
    def __init__(self):
        self.romanNumbers = {
            "I" : 1, "V": 5, "X": 10, "L": 50, "C": 100,
            "D": 500, "M": 1000
        }
        self.exceptions = {
            "IV": 4, "IX": 9,
            "XL": 40, "XC": 90,
            "CD": 400, "CM": 900
        }


    def romanToInt(self, s:str) -> int:
        result, i = 0, 0
        while i < len(s):
            if s[i:i + 2] in self.exceptions:
                result += self.exceptions[s[i:i + 2]]
                i += 2
            else:
                result += self.romanNumbers[s[i]]
                i += 1
        return result


if __name__ == "__main__":
    print(Solution().romanToInt("IIVI"))
