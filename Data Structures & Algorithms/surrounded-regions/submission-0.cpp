class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int r = board.size(), c = board[0].size();
        
        function<void(int, int)> dfs = 
            [&](int i, int j) {
                if (i < 0 || i >= r || j < 0 || j >= c 
                        || board[i][j] == 'X' || board[i][j] == 'Y') {
                    return;
                }
                board[i][j] = 'Y';
                for (auto [u, v] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                    dfs(i + u, j + v);
                }
            };

        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0);
            }
            if (board[i][c - 1] == 'O') {
                dfs(i, c - 1);
            }
        }

        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i);
            }
            if (board[r - 1][i] == 'O') {
                dfs(r - 1, i);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }

    }

    
};
