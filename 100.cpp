#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, trees are the same at this branch
        if (p == nullptr && q == nullptr) return true;
        // If one is null or values do not match, trees are not the same
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        // Recursively check left and right subtrees
        bool left_same = isSameTree(p->left, q->left);
        bool right_same = isSameTree(p->right, q->right);
        return left_same && right_same;
    }
};

int main() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(4);  // Different value to make the trees not the same

    Solution solution;
    bool result = solution.isSameTree(tree1, tree2);
    std::cout << "Are the trees the same? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
