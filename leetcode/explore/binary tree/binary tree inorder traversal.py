from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        nodeStack = []
        result = []
        curNode = root
        while curNode or nodeStack:
            while curNode:
                nodeStack.append(curNode)
                curNode = curNode.left
            curNode = nodeStack.pop()
            result.append(curNode.val)
            curNode = curNode.right
        return result

    def inorderRecursive(self, root: TreeNode) -> List[int]:
        if not root: return []

        res = self.inorderRecursive(root.left)
        res.append(root.val)
        res += self.inorderRecursive(root.right)

        return res



if __name__ == "__main__":
    tn = TreeNode(1)
    root = tn
    tn.right = TreeNode(2)
    tn = tn.right
    tn.left = TreeNode(3)
    print(Solution().inorderTraversal(root))
    print(Solution().inorderRecursive(root))