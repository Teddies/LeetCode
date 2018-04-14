// First use DFS to mark the marginal nodes
// Then convert the inner regions into 'X'
// And finally convert back the marked 'O' regions
class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'P';
        if (i - 1 >= 0 && board[i - 1][j] == 'O') {
            DFS(board, i - 1, j);
        }
        if (i + 1 < board.size() && board[i + 1][j] == 'O') {
            DFS(board, i + 1, j);
        }
        if (j - 1 >= 0 && board[i][j - 1] == 'O') {
            DFS(board, i, j - 1);
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == 'O') {
            DFS(board, i, j + 1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int n = board.size() - 1;
        int m = board[0].size() - 1;
        for (int i = 0; i <= m; ++ i) {
            if (board[0][i] == 'O') {
                DFS(board, 0, i);
            }
            if (board[n][i] == 'O') {
                DFS(board, n, i);
            }
        }
        
        for (int i = 0; i <= n; ++ i) {
            if (board[i][0] == 'O') {
                DFS(board, i, 0);
            }
            if (board[i][m] == 'O') {
                DFS(board, i, m);
            }
        }
        
        for (int i = 0; i < board.size(); ++ i) {
            for (int j = 0; j < board[0].size(); ++ j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
