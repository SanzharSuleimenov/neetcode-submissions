class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        deque<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push_back({i, j});
                }
            } 
        }

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int time = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            for (auto [ni, nj]: dir) {
                int u = i + ni;
                int v = j + nj;
                if (u >= 0 && u < r && v >= 0 && v < c && grid[u][v] == 1) {
                    grid[u][v] = grid[i][j] + 1;
                    q.push_back({u, v});
                    time = max(time, grid[u][v] - 2);
                }
            }    
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
