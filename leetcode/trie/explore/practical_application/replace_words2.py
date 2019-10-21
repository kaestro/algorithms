import collections
from typing import List

class TrieNode(object):
    
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isEnd = False

class Trie(object):

    def __init__(self):
        self.root = TrieNode()
    

    def insert(self, input: str) -> None:
        cur_node = self.root
        for letter in input:
            if cur_node.children.get(letter) == None:
                cur_node.children[letter] = TrieNode()
            cur_node = cur_node.children[letter]
        cur_node.isEnd = True
    

    def findShortestRoot(self, input: str) -> str:
        cur_node = self.root
        result = ""
        for letter in input:
            if cur_node.children.get(letter) == None:
                return input
            else:
                result += letter
                cur_node = cur_node.children[letter]
                if cur_node.isEnd:
                    return result
        if cur_node.isEnd:
            return result
        else:
            return input


class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        roots = Trie()
        for root in dict:
            roots.insert(root)
        
        sentence = sentence.split(" ")
        result = ""
        for word in sentence:
            result += roots.findShortestRoot(word) + " "
        return result[:-1]


if __name__ == "__main__":
    roots = ["cat", "bat", "rat"]
    sentence = "the cattle was rattled by the battery"
    print(Solution().replaceWords(roots, sentence))