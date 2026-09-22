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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }

private:
    bool isValid(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;

        if (minNode && node->val <= minNode->val) return false;
        if (maxNode && node->val >= maxNode->val) return false;

        return isValid(node->left, minNode, node)
            && isValid(node->right, node, maxNode);
    }
};