class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
         build adjecency list
         

         if ended up in loop, then finishing is impossible

         0 -> 1 -> 2 -> 3 -> 4 
              | ____    |

         0 = 0
         1 = 2, 1
         2 = 1, 0
         3 = 1, 
         4 = 1
         start with nodes of power = 0

        */

        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        
        for (auto course: prerequisites) {
            indegree[course[1]]++;
            adj[course[0]].push_back(course[1]);
        }
        
        deque<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push_back(i);
            }
        }

        int finished = 0;

        while (!q.empty()) {
            int c = q.front();
            q.pop_front();
            finished++;
            for (int next: adj[c]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push_back(next);
                }
            }
        }

        return finished == numCourses;
    }
};
