/*
 * Problem 199: Binary Tree Right Side View
 * Time Complexity: O(N) - Every node is visited exactly once during the BFS traversal.
 * Space Complexity: O(N) - The queue holds at most N/2 nodes at the widest level of a balanced tree.
 * Note: BFS with level-locking using a queue. The rightmost node is captured when the loop index reaches 1.
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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> resTab;
        std::queue<TreeNode*> q;

        if (!root)
            return resTab;
        q.push(root);
        while (!q.empty())
        {
             for (int i = q.size(); i > 0; --i)
             {
                if (i == 1)
                    resTab.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return resTab;
    }
};