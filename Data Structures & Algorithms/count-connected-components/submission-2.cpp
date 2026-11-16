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

    bool join(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) {
            return false;
        }
        if (SIZE[ru] >= SIZE[rv]) {
            ROOT[rv] = ru;
            SIZE[ru] += SIZE[rv];
        } else {
            ROOT[ru] = rv;
            SIZE[rv] += SIZE[ru];
        }
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int count = n;
        for (const auto& e : edges)
            if (dsu.join(e[0], e[1])) count--;
        return count;
    }
};
