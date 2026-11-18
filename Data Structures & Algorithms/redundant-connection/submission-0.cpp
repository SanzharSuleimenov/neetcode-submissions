class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> deg(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            deg[u] = 0;
            for (int v : adj[u]) {
                if (deg[v] == 0) continue;    // already pruned
                if (--deg[v] == 1) q.push(v);
            }
        }

        for (int i = n - 1; i >= 0; i--)
            if (deg[edges[i][0]] == 2 && deg[edges[i][1]] == 2)
                return edges[i];

        return {};
    }
};
