from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        nodeStack = [root]
        result = []
        while nodeStack:
            cur = nodeStack.pop()
            result.append(cur.val)
            if cur.left:
                nodeStack.append(cur.left)
            if cur.right:
                nodeStack.append(cur.right)
        return result[::-1]
    
    def postorderTraversal_recursive(self, root: TreeNode) -> List[int]:
        nodeStack = []
        self.helper(root, nodeStack)
        return nodeStack
    

    def helper(self, root: TreeNode, nodeStack: List[int]):
        if not root:
            return
        
        self.helper(root.left, nodeStack)
        self.helper(root.right, nodeStack)
        nodeStack.append(root.val)


if __name__ == "__main__":
    tn = TreeNode(1)
    cur = tn
    cur.right = TreeNode(2)
    cur = cur.right
    cur.left = TreeNode(3)
    print(Solution().postorderTraversal(tn))
    print(Solution().postorderTraversal_recursive(tn))