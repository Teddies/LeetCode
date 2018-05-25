class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> hash;
        vector<unordered_map<int, int>> row(9, hash);
        vector<unordered_map<int, int>> column(9, hash);
        vector<unordered_map<int, int>> square(9, hash);
        
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < 9; ++ j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    if (row[i].find(n) != row[i].end()) return false;
                    if (column[j].find(n) != column[j].end()) return false;
                    int index = j / 3 * 3 + i / 3;
                    if (square[index].find(n) != square[index].end()) return false;
                    row[i][n] = 1;
                    column[j][n] = 1;
                    square[index][n] = 1;
                }
            }
        }
        return true;
    }
};