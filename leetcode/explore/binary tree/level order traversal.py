from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        nodeQueue = [root]
        result = []
        while nodeQueue:
            row = []
            nextQueue = []
            while nodeQueue:
                curNode = nodeQueue.pop()
                row.append(curNode.val)
                if curNode.left:
                    nextQueue.insert(0, curNode.left)
                if curNode.right:
                    nextQueue.insert(0, curNode.right)
            result.append(row)
            nodeQueue = nextQueue
        
        return result