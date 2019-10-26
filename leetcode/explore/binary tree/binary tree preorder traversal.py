from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                result.append(node.val)
                stack.append(node.right)
                stack.append(node.left)
        
        return result


if __name__ == "__main__":
    input = TreeNode(1)
    input.right = TreeNode(2)
    cur= input.right
    cur.left = TreeNode(3)
    cur = cur.left
    print(Solution().preorderTraversal(input))