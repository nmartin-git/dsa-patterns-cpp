/*
 * Problem 124: Binary Tree Maximum Path Sum (Hard)
 * Time Complexity: O(N) - We visit every node exactly once.
 * Space Complexity: O(H) - Where H is the height of the tree (worst-case O(N) for an unbalanced tree, O(log N) for balanced) due to the call stack.
 * Note: Uses a bottom-up DFS (post-order traversal). Negative sub-paths are pruned using max(0, path).
 */

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
    int dfs(TreeNode* root, int& maxPath) {
        int leftPath, rightPath;
        if (!root)
            return 0;
        leftPath = std::max(dfs(root->left, maxPath), 0);
        rightPath = std::max(dfs(root->right, maxPath), 0);
        maxPath = std::max(root->val + leftPath + rightPath, maxPath);
        return root->val + std::max(leftPath, rightPath);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int maxPath = root->val;
        return std::max(dfs(root, maxPath), maxPath);
    }
};
