#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> nodeStack;
        vector<int> result;
        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            auto curNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(curNode->val);
            if (curNode->left) nodeStack.push(curNode->left);
            if (curNode->right) nodeStack.push(curNode->right);
        }
        reverse(result.begin(), result.end());
        
        return result;
    }

    vector<int> postorderTraversal_recursive(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int>& result) {
        if (!root) return;
        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    auto cur = root;
    cur->right = new TreeNode(2);
    cur = cur->right;
    cur->left = new TreeNode(3);
    Solution s;
    s.postorderTraversal(root);
}