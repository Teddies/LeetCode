class Solution {
public:
    unordered_map<int, set<int>> rows, columns, square;
    
    bool fill(int i, int j, vector<vector<char>>& board) {
        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; ++ k) {
                if (rows[i].find(k) == rows[i].end() && 
                    columns[j].find(k) == columns[j].end() && 
                    square[i / 3 * 3 + j / 3].find(k) == square[i / 3 * 3 + j / 3].end()) {
                    board[i][j] = '0' + k;
                    rows[i].insert(k);
                    columns[j].insert(k);
                    square[i / 3 * 3 + j / 3].insert(k);
                    if (i == 8 && j == 8) return true;
                    else if (j == 8) {
                        if (fill(i + 1, 0, board) == true) return true;
                        else {
                            rows[i].erase(rows[i].find(k));
                            columns[j].erase(columns[j].find(k));
                            square[i / 3 * 3 + j / 3].erase(square[i / 3 * 3 + j / 3].find(k));
                            board[i][j] = '.';
                        }
                    }
                    else {
                        if (fill(i, j + 1, board) == true) return true;
                        else {
                            rows[i].erase(rows[i].find(k));
                            columns[j].erase(columns[j].find(k));
                            square[i / 3 * 3 + j / 3].erase(square[i / 3 * 3 + j / 3].find(k));
                            board[i][j] = '.';
                        }
                    } 
                }
            }
            return false;
        }
        else {
            if (i == 8 && j == 8) return true;
            else if (j == 8) return fill(i + 1, 0, board);
            else return fill(i, j + 1, board);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < 9; ++ j) {
                if (board[i][j] != '.') {
                    rows[i].insert(board[i][j] - '0');
                    columns[j].insert(board[i][j] - '0');
                    square[i / 3 * 3 + j / 3].insert(board[i][j] - '0');
                }
            }
        }
        fill(0, 0, board);
    }
};