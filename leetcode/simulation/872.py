from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        return self.leafSequence(root1) == self.leafSequence(root2)
        
    def leafSequence(self, root: TreeNode) -> List:
        if not root: return[]
        if not (root.left or root.right): return [root.val]
        return self.leafSequence(root.left) + self.leafSequence(root.right)
