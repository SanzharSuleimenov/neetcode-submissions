class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
            1. We will reuse grid as a visited and un-visited matrix. If land was visited, we set it to '0'. 
            2. iterate over the grid
                2.1. If we met '1' / land then we start [DFS/BFS]
                2.2. Once cell is visited we set value as '0'
                2.3. each time [BFS/DFS] is triggered we increase land counter by 1
            3. return land counter
        */
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
