/*
 * Problem 98: Validate Binary Search Tree
 * Time Complexity: O(N) - We visit every node exactly once.
 * Space Complexity: O(N) - Worst case recursion stack for an unbalanced tree, O(log N) for a balanced tree.
 * Note: Used TreeNode* for min/max boundaries instead of LONG_MIN/LONG_MAX to handle extreme integer values for understanding.
 */

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
private:
    bool checkBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root)
            return true;
        if ((min && root->val <= min->val) || (max && root->val >= max->val))
            return false;
        return checkBST(root->left, min, root) && checkBST(root->right, root, max); 
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, nullptr, nullptr);
    }
};