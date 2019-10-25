#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1, t2;
        findLeafSequence(root1, t1);
        findLeafSequence(root2, t2);
        return t1 == t2;
    }

    void findLeafSequence(TreeNode* root, string& sequence) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL)
            sequence += to_string(root->val) + " ";
        findLeafSequence(root->left, sequence);
        findLeafSequence(root->right, sequence);
    }
};