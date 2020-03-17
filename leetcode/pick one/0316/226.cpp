#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

int main() {
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    one->left = two;
    Solution s;
    s.invertTree(one);

    cout << endl;

    return 0;
}