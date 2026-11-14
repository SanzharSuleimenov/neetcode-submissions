class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> pac(r, vector<bool>(c)), atl(r, vector<bool>(c));
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int i, int j, vector<vector<bool>>& visited) {
            visited[i][j] = 1;
            for (auto [ni, nj]: vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int di = i + ni, dj = j + nj;
                if (di >= 0 && di < r && dj >= 0 && dj < c && !visited[di][dj] && heights[i][j] <= heights[di][dj]) {
                    dfs(di, dj, visited);
                }
            }
        };

        for (int i = 0; i < c; i++) {
            dfs(0, i, pac);
            dfs(r - 1, i, atl);
        }
        for (int i = 0; i < r; i++) {
            dfs(i, 0, pac);
            dfs(i, c - 1, atl);
        }

        vector<vector<int>> result;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (atl[i][j] && pac[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    
};
