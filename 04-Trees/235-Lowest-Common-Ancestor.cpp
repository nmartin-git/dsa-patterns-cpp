/*
 * Problem 235: Lowest Common Ancestor of a Binary Search Tree
 * Time Complexity: O(N) in worst case (unbalanced tree), O(log N) in balanced tree.
 * Space Complexity: O(1) - Iterative approach prevents call stack overflow.
 */

#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int maxVal = std::max(p->val, q->val);
        int minVal = std::min(p->val, q->val);
        while (root) {
            if (root->val > maxVal)
                root = root->left;
            else if (root->val < minVal)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};