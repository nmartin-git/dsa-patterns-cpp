/*
 * Problem 230: Kth Smallest Element in a Binary Search Tree
 * Time Complexity: O(N) - In the worst case, we call the recursive function on each node.
 * Space Complexity: O(N) - Space required by the recursion stack, a call on each node in the worst case.
 * Note: Used an inorder traversal (DFS) with early exit to instantly break the recursion chain when k reaches 0.
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
    int checkKthSmallest(TreeNode* root, int &k) {
        int res;
        if (!root)
            return -1;
        res = checkKthSmallest(root->left, k);
        if (k == 0)
            return res;
        --k;
        if (k == 0)
            return root->val;
        return checkKthSmallest(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return checkKthSmallest(root, k);
    }
};