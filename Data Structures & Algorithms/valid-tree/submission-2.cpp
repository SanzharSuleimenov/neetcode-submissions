class DSU {
    vector<int> ROOT, POWER;
    public: 
    DSU(int n) {

    }
};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.size() == 0) return true;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            indegree[edges[i][1]]++;
            indegree[edges[i][0]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                dq.push_back(i);
            }
        }

        int visited = 0;
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            visited++;
            for (int v: adj[u]) {
                indegree[v]--;
                if (indegree[v] == 1) {
                    dq.push_back(v);
                }
            }
        }

        return visited == n && edges.size() == n - 1;
    }
};
