#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {{}};

        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            vector<int> row;
            queue<TreeNode*> nextQueue;
            while (!nodeQueue.empty())
            {
                auto oldestNode = nodeQueue.front();
                nodeQueue.pop();
                row.push_back(oldestNode->val);
                if (oldestNode->left)
                    nextQueue.push(oldestNode->left);
                if (oldestNode->right)
                    nextQueue.push(oldestNode->right);
            }
            result.push_back(row);
            nodeQueue = nextQueue;
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    auto cur = root;
    cur->left = new TreeNode(9);
    cur->right = new TreeNode(20);
    cur = cur->right;
    cur->left = new TreeNode(15);
    cur->right = new TreeNode(7);

    Solution s;
    s.levelOrder(root);

    return 0;
}