import collections

class TrieNode:
    
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.value = 0


class MapSum:

    def __init__(self):
        self.root = TrieNode()
        

    def insert(self, key: str, val: int) -> None:
        cur_node = self.root
        for letter in key:
            cur_node = cur_node.children[letter]
        cur_node.value = val
        

    def sum(self, prefix: str) -> int:
        cur_node = self.root
        result = 0
        for letter in prefix:
            next_node = cur_node.children.get(letter)
            if next_node == None:
                return 0
            else:
                cur_node = next_node

        result += cur_node.value
        for suffixes in cur_node.children:
            result += self.sum(prefix + suffixes)
        
        return result
        



if __name__ == "__main__":
    example = MapSum()
    print(example.insert("apple", 3))
    print(example.sum("ap"))
    print(example.insert("app", 2))
    print(example.sum("ap"))



        


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)