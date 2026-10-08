/*
 * Problem 210: Course Schedule II
 * Time Complexity: O(V + E) - Where V is numCourses (Vertices) and E is the number of prerequisites (Edges). We visit each course and its edges at most once.
 * Space Complexity: O(V + E) - Space required to build the adjacency list, the in-degree array, and the queue.
 * Note: Modeled as a Directed Graph. Uses Kahn's Algorithm (BFS) with in-degree counting for Topological Sort and cycle detection.
 */

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::queue<int> q;
        std::vector<int> resTab;
        std::vector<int> preCount(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses);
        int pSize = prerequisites.size();
        int tmp;

        for (int i = 0; i < pSize; ++i) {
            ++preCount[prerequisites[i][0]];
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (preCount[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            resTab.push_back(tmp);
            for (int course: adj[tmp]) {
                    if (--preCount[course] == 0)
                        q.push(course);
            }
        }
        if (resTab.size() != numCourses)
            return {};
        return resTab;
    }
};