import collections

class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isWord = False

class Trie:

    def __init__(self):
        self.root = TrieNode()
        

    def insert(self, word: str) -> None:
        curNode = self.root
        for letter in word:
            curNode = curNode.children[letter]
        curNode.isWord = True
        

    def search(self, word: str) -> bool:
        curNode = self.root
        for letter in word:
            curNode = curNode.children.get(letter)
            if curNode is None:
                return False

        return curNode.isWord

        

    def startsWith(self, prefix: str) -> bool:
        curNode = self.root
        for letter in prefix:
            curNode = curNode.children.get(letter)
            if curNode is None:
                return False
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)