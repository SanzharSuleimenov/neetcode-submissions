class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        bfs(q, grid);
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dist = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i - 1 >= 0 && grid[i - 1][j] == 2147483647) {
                grid[i - 1][j] = grid[i][j] + 1;
                q.push({i - 1, j});
            }
            if (i + 1 < r && grid[i + 1][j] == 2147483647) {
                grid[i + 1][j] = grid[i][j] + 1;
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 2147483647) {
                grid[i][j - 1] = grid[i][j] + 1;
                q.push({i, j - 1});
            }
            if (j + 1 < c && grid[i][j + 1] == 2147483647) {
                grid[i][j + 1] = grid[i][j] + 1;
                q.push({i, j + 1});
            }
        }
    }

};
