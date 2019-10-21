class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        result = ""
        sentence = sentence.split(' ')
        for word in sentence:
            for root in dict:
                if word.find(root) == 0:
                    word = root
                    break
            result += word + " "

        return result[:-1]