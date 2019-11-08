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
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        TreeNode* curr = root;
        while (curr || !stack.empty()) {
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top(); stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
};