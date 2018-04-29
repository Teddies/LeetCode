class Solution {
public:
    int countMines(vector<vector<char>>& board, int i, int j, int n, int m) {
        int res = 0;
        if (i - 1 >= 0) {
            if (j - 1 >= 0 && board[i - 1][j - 1] == 'M') res ++;
            if (board[i - 1][j] == 'M') res ++;
            if (j + 1 < m && board[i - 1][j + 1] == 'M') res ++;
        }     
        if (j - 1 >= 0 && board[i][j - 1] == 'M') res ++;
        if (j + 1 < m && board[i][j + 1] == 'M') res ++;
        if (i + 1 < n) {
            if (j - 1 >= 0 && board[i + 1][j - 1] == 'M') res ++;
            if (board[i + 1][j] == 'M') res ++;
            if (j + 1 < m && board[i + 1][j + 1] == 'M') res ++;
        }
        return res;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<vector<int>> q;
        q.push(click);
        int n = board.size(), m = board[0].size();
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++ k) {
                int i = q.front()[0];
                int j = q.front()[1];
                if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'E') {
                    q.pop();
                    continue;
                }
                int count = countMines(board, i, j, n, m);
                if (count == 0) {
                    board[i][j] = 'B';
                    vector<int> v(2, 0);
                    v[0] = i - 1; v[1] = j - 1; q.push(v);
                    v[1] = j; q.push(v); v[1] = j + 1; q.push(v);
                    v[0] = i; q.push(v); v[1]= j - 1; q.push(v);
                    v[0] = i + 1; q.push(v); v[1] = j; q.push(v);
                    v[1] = j + 1; q.push(v);
                }
                else {
                    board[i][j] = count + '0';
                }
                q.pop();
            }
        }
        return board;
    }
};