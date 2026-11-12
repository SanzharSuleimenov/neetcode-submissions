class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int lands = 1;
        lands += dfs(i + 1, j, grid);
        lands += dfs(i - 1, j, grid);
        lands += dfs(i, j + 1, grid);
        lands += dfs(i, j - 1, grid);
        return lands;
    }
};
