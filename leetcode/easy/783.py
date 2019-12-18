# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        nums = self.inorder(root)
        return min(nums[i+1] - nums[i] for i in range(len(nums)-1))

    def inorder(self, root):
        return self.inorder(root.left) + [root.val] + self.inorder(root.right) if root else []



if __name__ == "__main__":
    root = TreeNode(4)
    two = TreeNode(2)
    one = TreeNode(1)
    three = TreeNode(3)
    six = TreeNode(6)
    root.left = two
    two.left = one
    two.right = three
    root.right = six

    print(Solution().minDiffInBST(root))

