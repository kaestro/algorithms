#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode* merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t1_1 = new TreeNode(3);
    TreeNode* t1_2 = new TreeNode(2);
    TreeNode* t1_3 = new TreeNode(5);

    t1->left = t1_1;
    t1->right = t1_2;
    t1_1->left = t1_3;

    TreeNode* t2 = new TreeNode(2);
    TreeNode* t2_1 = new TreeNode(1);
    TreeNode* t2_2 = new TreeNode(3);
    TreeNode* t2_3 = new TreeNode(4);
    TreeNode* t2_4 = new TreeNode(7);

    t2->left = t2_1;
    t2->right = t2_2;
    t2_1->right = t2_3;
    t2_2->right = t2_4;

    Solution s;
    auto* ans = s.mergeTrees(t1, t2);

    cout << endl;

    return 0;
}