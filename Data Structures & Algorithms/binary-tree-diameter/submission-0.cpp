#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }

private:
    int dfs(TreeNode* node, int& diameter) {
        if (!node) {
            return 0; // Base case: height of empty tree is 0
        }

        // Recursively compute heights of left and right subtrees
        int leftHeight = dfs(node->left, diameter);
        int rightHeight = dfs(node->right, diameter);

        // Update the global maximum diameter (path through current node)
        diameter = std::max(diameter, leftHeight + rightHeight);

        // Return height of current node's subtree to parent
        return 1 + std::max(leftHeight, rightHeight);
    }
};