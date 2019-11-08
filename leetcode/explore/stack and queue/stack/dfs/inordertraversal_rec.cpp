#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode* root, std::vector<int>& ans) {
        if (root) {
            if (root->left) {
                helper(root->left, ans);
            }
            ans.push_back(root->val);
            if (root->right) {
                helper(root->right, ans);
            }
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    root->right = two;
    two->left = three;

    Solution s;
    auto res = s.inorderTraversal(root);

    return 0;
}