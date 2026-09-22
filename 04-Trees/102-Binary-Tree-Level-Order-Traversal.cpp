/*
 * Problem 102: Binary Tree Level Order Traversal
 * Time Complexity: O(N) - We visit every node exactly once to process its value.
 * Space Complexity: O(N) - The queue holds at most N/2 nodes at the widest level of a balanced tree.
 * Note: Used an iterative Breadth-First Search (BFS) with a queue and size-locking (snapshot of q.size()) to isolate levels without recursion.
 */

#include <vector>
#include <queue>

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
    std::vector<std::vector<int>>   levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> resTab;
        std::vector<int> tmp;
        std::queue<TreeNode *> q;

        if (!root)
            return resTab;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                tmp.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            resTab.push_back(tmp);
            tmp.clear();
        }
        return resTab;
    }
};