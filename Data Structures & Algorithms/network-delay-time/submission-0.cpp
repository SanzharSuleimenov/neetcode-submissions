class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});
        for (auto& v : adj) sort(v.begin(), v.end(),
            [](auto& a, auto& b){ return a.second < b.second; }); // cheap edges first

        vector<int> dist(n + 1, INT_MAX);
        dfs(k, 0, adj, dist);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    void dfs(int u, int time, vector<vector<pair<int,int>>>& adj, vector<int>& dist) {
        if (time >= dist[u]) return;   // only continue if strictly better
        dist[u] = time;
        for (auto& [v, w] : adj[u]) dfs(v, time + w, adj, dist);
    }
};