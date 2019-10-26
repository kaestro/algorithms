class Solution:
    def __init__(self):
        self.vowels = 'aeiouAEIOU'


    def toGoatLatin(self, S: str) -> str:
        goatLatin = ""
        words = S.split()
        for i, word in zip(range(1, len(words) + 1), words):
            if word[0] in self.vowels:
                goatLatin += word + "ma" + "a" * i + " "
            else:
                goatLatin += word[1:] + word[0] + "ma" + "a" * i + " "
        return goatLatin[:-1]
    

if __name__ == "__main__":
    print(Solution().toGoatLatin("I speak Goat Latin"))
    

