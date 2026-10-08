/*
 * Problem 547: Number of Provinces
 * Time Complexity: O(N^2) - We iterate through the strictly upper triangle of the N x N symmetric adjacency matrix.
 * Space Complexity: O(N) - For the parent and rank arrays used in the Disjoint Set Union.
 * Note: DSU is ideal here. The graph is undirected, so we avoid redundant unions by skipping the diagonal and the lower half.
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

    void unionFind(int& provincesCount, int r, int c) {
        int rRoot = find(r);
        int cRoot = find(c);

        if (rRoot == cRoot)
            return;
        --provincesCount;
        if (rank[rRoot] > rank[cRoot])
            parent[cRoot] = rRoot;
        else if (rank[cRoot] > rank[rRoot])
            parent[rRoot] = cRoot;
        else {
            parent[cRoot] = rRoot;
            ++rank[rRoot];
        }
        return;
    } 

    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int mapSize = isConnected.size();
        int provincesCount = mapSize;

        parent.resize(mapSize);
        rank.resize(mapSize, 0);
        for (int i = 0; i < mapSize; ++i)
            parent[i] = i;
        for (int r = 0; r < mapSize; ++r) {
            for (int c = r + 1; c < mapSize; ++c) {
                if (isConnected[r][c] == 1)
                    unionFind(provincesCount, r, c);
            }
        }
        return provincesCount;
    }
};