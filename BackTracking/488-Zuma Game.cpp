class Solution {
public:
    int res;
    
    Solution() {
        res = INT_MAX;
    }
    
    void clear(string& str) {
        if (str.empty() || str.size() < 3) return;
        int val = 1;
        char target = str[0];
        for (int i = 1; i < str.size(); ++ i) {
            if (str[i] != target) {
                if (val >= 3) {
                    str.erase(str.begin() + i - val, str.begin() + i);
                    i -= val;
                }
                target = str[i];
                val = 1;
            }
            else val ++;
        }
        if (val >= 3)
            str.erase(str.begin() + str.size() - val, str.end());
    }
    
    void DFS(int index, string& board, unordered_map<char, int>& hash, int& temp) { 
        if (board.empty()) {
            res = min(res, temp);
            return;
        }
        if (board.size() == 1) {
            if (hash[board[0]] >= 2) {
                res = min(res, temp + 2);
            }
            return;
        }
        for (int k = index; k < board.size(); ++ k) {
            char target = board[k];
            int n = 1;
            for (int i = k + 1; i < board.size(); ++ i) {
                if (board[i] == target) n ++;
                else break; 
            }
            // Backtracking
            if (hash[target] >= 3 - n) {
                hash[target] -= 3 - n;
                temp += 3 - n;
                string str = board;
                str.erase(str.begin() + k, str.begin() + k + n);
                // IMPOERTANT: here we must clear the repeatitive elements RECURSIVELY 
                // (clear the string multiple times until the size of the string doesn't change)
                int size;
                do {
                    size = str.size();
                    clear(str);
                } while (size != str.size());
                DFS(0, str, hash, temp);
                hash[target] += 3 - n;
                temp -= 3 - n;
            }
            k += n - 1;
        }
    }
    
    int findMinStep(string board, string hand) {
        unordered_map<char, int> hash;
        for (int i = 0; i < hand.size(); ++ i) {
            hash[hand[i]] ++;
        }
        int temp = 0;
        DFS(0, board, hash, temp);
        if (res == INT_MAX) return -1;
        else return res;
    }
};