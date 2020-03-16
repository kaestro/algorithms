# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.tlist = []


    def balanceBST(self, root: TreeNode) -> TreeNode:
        self.traverse(root)
        ans_root = TreeNode(0)
        self.createBST(ans_root, 0, len(self.tlist))
        return ans_root



    def traverse(self, root: TreeNode) -> None:
        if root is None:
            return
        
        self.traverse(root.left)
        self.tlist.append(root.val)
        self.traverse(root.right)
    

    def createBST(self, root: TreeNode, lhs:int, rhs:int) -> None:
        if lhs >= rhs: return
        mid = (lhs + rhs) // 2
        root.val = self.tlist[mid]
        if lhs < mid:
            root.left = TreeNode(0)
            self.createBST(root.left, lhs, mid)
        if mid+1 < rhs:
            root.right = TreeNode(0)
            self.createBST(root.right, mid + 1, rhs)


if __name__ == "__main__":
    one = TreeNode(1)
    two = TreeNode(2)
    three = TreeNode(3)
    four = TreeNode(4)
    one.right = two
    two.right = three
    three.right = four
    Solution().balanceBST(one)