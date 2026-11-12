class DSU {
    vector<int> Parent, Size;
    public:
        DSU(int n) {
            Parent.resize(n + 1);
            Size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                Parent[i] = i;
                Size[i] = 1;
            }
        }

        int find(int node) {
            if (node != Parent[node]) {
                Parent[node] = find(Parent[node]);
            }
            return Parent[node];
        }

        bool unionBySize(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false;
            if (Size[pu] >= Size[pv]) {
                Size[pu] += Size[pv];
                Parent[pv] = pu;
            } else {
                Size[pv] += Size[pu];
                Parent[pu] = pv;
            }
            return true;
        }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m);

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int islands = 0;

        auto index = [&](int r, int c) {
            return r * m + c;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    for (auto& d: directions) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni >=0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                            if (dsu.unionBySize(index(i, j), index(ni, nj))) {
                                islands--;
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }

    int bfsAndDfs(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;   
                }
            }
        }
        return islands;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
        }
    }

    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<vector<int>> next;
        next.push({i, j});
        while (next.size() > 0) {
            int r = next.front()[0];
            int c = next.front()[1];
            next.pop();
            if (grid[r][c] == '0') continue;
            if (r + 1 < grid.size() && grid[r + 1][c] == '1') {
                next.push({r + 1, c});
            }
            if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                next.push({r - 1, c});
            }
            if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                next.push({r, c - 1});
            }
            if (c + 1 < grid[0].size() && grid[r][c + 1] == '1') {
                next.push({r, c + 1});
            }
            grid[r][c] = '0';
        }
    }
};