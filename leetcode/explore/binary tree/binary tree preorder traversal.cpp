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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            auto node = nodeStack.top();
            nodeStack.pop();
            if (node != NULL)
            {
                result.push_back(node->val);
                nodeStack.push(node->right);
                nodeStack.push(node->left);
            }
        }

        return result;
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* cur = root;
    cur->right = new TreeNode(2);
    cur = cur->right;
    cur->left = new TreeNode(3);
    Solution s;
    s.preorderTraversal(root);

    return 0;
}