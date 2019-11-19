#include <vector>

const bool Left = 0, Right = 1;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
 private:
    TreeNode* cur_root;
 public:
    FindElements(TreeNode* root) {
        cur_root = root;
        recover(root, 0);
    }

    void recover(TreeNode* root, int val) {
        if (!root) return;

        root->val = val;
        if (root->left) {
            recover(root->left, 2 * val + 1);
        }
        if (root->right) {
            recover(root->right, 2 * val + 2);
        }
    }
    
    bool find(int target) {
        std::vector<bool> direction;
        while (target > 0) {
            if (target % 2) {
                direction.push_back(Left);
            } else {
                direction.push_back(Right);
            }
            target = (target-1)/2;
        }

        auto curr = cur_root;
        for (auto bit = direction.rbegin(); bit != direction.rend(); ++bit) {
            if (*bit == Left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
            if (!curr) return false;
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(-1);
    root->right = new TreeNode(-1);
    FindElements fe(root);
    auto ans = fe.find(1);
    ans = fe.find(2);

    return 0;
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */