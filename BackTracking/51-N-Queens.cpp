// Backtracking: first try the possible values and return back to the original value 
// if it fails (also success, but if it success, the results are saved) with recursion.

// Notice that the initial value of "board" are -1 instead of constant 0.
// When marking the values in the board, we should not always use the same value.
// Instead, we use the value of variable "line". This is because one position is
// influenced by multiple "Queens", and when we remove the influence of the current Queen,
// which means when we return from the recursion, we should keep the influence of the other
// Queens. For example:

// Q 1 1 1 
// 1 1 Q 2
// 1 2 1 2
// 1 . 2 1

// The positions marking with 1 are controlled by the Queen in the first line
// The positions marking with 2 are controlled by the Queen in the second line
// There are overlaps between these Queens, but when we remove the second line Queen
// We should keep the positions marking with 1 although they are also controlled by
// the second Queen. Than's why we need to use differnt values to mark the positions.

class Solution {
public:
    vector<vector<string>> res;
    
    bool put(int line, int n, vector<string>& vec, vector<vector<int>>& board) {
        if (line == n) {
            res.push_back(vec);
            return true;
        }

        for (int i = 0; i < n; ++ i) {
            if (board[line][i] != -1) continue;
            vec[line][i] = 'Q';
            for (int j = 0; j < n; ++ j) {
                // Mark the row, colume and the two diagonoses lines
                // Mark the value of line instead of a constant variable
                if (board[line][j] == -1) board[line][j] = line;
                if (board[j][i] == -1) board[j][i] = line;
                if (i - j + line >= 0 && i - j + line < n && board[j][i - j + line] == -1) board[j][i - j + line] = line;
                if (i + j - line >= 0 && i + j - line < n && board[j][i + j - line] == -1) board[j][i + j - line] = line;
            }
            
            put(line + 1, n, vec, board);
            
            // Return the values back
            vec[line][i] = '.';
            for (int j = 0; j < n; ++ j) {
                if (board[j][i] == line) board[j][i] = -1;
                if (board[line][j] == line) board[line][j] = -1;
                if (i - j + line >= 0 && i - j + line < n && board[j][i - j + line] == line) board[j][i - j + line] = -1;
                if (i + j - line >= 0 && i + j - line < n && board[j][i + j - line] == line) board[j][i + j - line] = -1;
            }
        }
        
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string str;
        for (int i = 0; i < n; ++ i) str.push_back('.');
        vector<vector<int>> board(n, vector<int>(n, -1));
        vector<string> vec(n, str);
        // From the line 0, start recursion
        put(0, n, vec, board);  
        return res;
    }
};