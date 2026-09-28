/*
 * Problem 684: Redundant Connection (Medium)
 * Time Complexity: O(N * α(N)) ≈ O(N) - Disjoint Set Union with Path Compression and Union by Rank.
 * Space Complexity: O(N) - For parent and rank arrays.
 * Note: DSU is ideal here. If two nodes being connected already share the same root, the edge forms a cycle.
 */

#include <vector>

class Solution {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionFind(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            ++rank[rootX];
        }
        return true;
    }
    std::vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int eSize = edges.size();
        parent.resize(eSize + 1);
        rank.resize(eSize + 1, 1);
        for (int i = 0; i <= eSize; ++i)
            parent[i] = i;
        for (int i = 0; i < eSize; ++i) {
            if (!unionFind(edges[i][0], edges[i][1]))
                return edges[i];
        }
        return {};
    }
};