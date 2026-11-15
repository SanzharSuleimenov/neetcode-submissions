class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto p: prerequisites) {
            indegree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }

        vector<int> courses;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                courses.push_back(i);
            }
        }

        for (int i = 0; i < courses.size(); i++) {
            int course = courses[i];
            for (int j = 0; j < adj[course].size(); j++) {
                int next = adj[course][j];
                indegree[next]--;
                if (indegree[next] == 0) {
                    courses.push_back(next);
                }
            }
        }

        if (courses.size() == numCourses) {
            return courses;
        }
        return {};
    }
};
