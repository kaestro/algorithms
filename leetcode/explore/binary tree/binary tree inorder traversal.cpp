#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        auto curNode = root;
        while (curNode != NULL || !nodeStack.empty())
        {
            while (curNode != NULL)
            {
                nodeStack.push(curNode);
                curNode = curNode->left;
            }
            curNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(curNode->val);
            curNode = curNode->right;
        }
        return result;
    }

    vector<int> inorderTraversalRecurvise(TreeNode* root) {
        vector<int> result;
        recursiveHelper(root, result);
        return result;
    }

    void recursiveHelper(TreeNode* root, vector<int>& result) {
        if (!root) return;

        recursiveHelper(root->left, result);
        result.push_back(root->val);
        recursiveHelper(root->right, result);
    }
};