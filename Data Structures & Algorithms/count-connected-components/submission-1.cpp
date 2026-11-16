class DSU {
    vector<int> ROOT, SIZE;
public:
    DSU(int n) {
        ROOT.resize(n);
        SIZE.resize(n);
        for (int i = 0; i < n; i++) {
            ROOT[i] = i;
            SIZE[i] = 1;
        }
    }

    int find(int node) {
        if (ROOT[node] != node) {
            ROOT[node] = find(ROOT[node]);
        }
        return ROOT[node];
    }

    void join(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) {
            return;
        }
        if (SIZE[ru] >= SIZE[rv]) {
            ROOT[rv] = ru;
            SIZE[ru] += SIZE[rv];
        } else {
            ROOT[ru] = rv;
            SIZE[rv] += SIZE[ru];
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto edge: edges) {
            dsu.join(edge[0], edge[1]);
        }

        set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(dsu.find(i));
        }

        return components.size();
    }
};
