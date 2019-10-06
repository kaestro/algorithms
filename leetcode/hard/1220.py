class Solution:
    def countVowelPermutation(self, n: int) -> int:
        res = {}
        def dynamic(step, numbers):
            if (step == 1):
                for vowel in "aeiou":
                    numbers[vowel] = 1
                return numbers
            numbers = dynamic(step - 1, numbers)
            res = {}
            for vowel in "aeiou":
                if vowel == 'a':
                    res[vowel] = numbers['e']
                elif vowel == 'e':
                    res[vowel] = numbers['a'] + numbers['i']
                elif vowel == 'o':
                    res[vowel] = numbers['i'] + numbers['u']
                elif vowel == 'u':
                    res[vowel] = numbers['a']
                else:
                    res[vowel] = sum(numbers.values()) - numbers['i']
            return res
        res = dynamic(n, res)
        return sum(res.values())


if __name__ == "__main__":
    for i in range(1, 6):
        print(Solution().countVowelPermutation(i))