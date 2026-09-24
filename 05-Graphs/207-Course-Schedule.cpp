/*
 * Problem 207: Course Schedule
 * Time Complexity: O(V + E) - Where V is numCourses (Vertices) and E is the number of prerequisites (Edges). We visit each course and its edges at most once.
 * Space Complexity: O(V + E) - Space required to build the adjacency list and the maximum depth of the recursion stack.
 * Note: Modeled as a Directed Graph. Cycle detection is implemented using DFS with a 3-state coloring algorithm
 */

#include <vector>

class Solution {
public:
    bool dfs(int course, std::vector<std::vector<int>>& cPrereq, std::vector<int>& visited) {
        if (visited[course] == 1)
            return false;
        if (visited[course] == 2)
            return true;
        visited[course] = 1;
        for (int nextCourse: cPrereq[course])
        {
            if (!dfs(nextCourse, cPrereq, visited))
                return false;
        }
        visited[course] = 2;
        return true;     
    }

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> cPrereq(numCourses);
        std::vector<int> visited(numCourses, 0);
        int reqSize = prerequisites.size();

        for (int i = 0; i < reqSize; ++i) {
            cPrereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, cPrereq, visited))
                return false;
        }
        return true;
    }
};