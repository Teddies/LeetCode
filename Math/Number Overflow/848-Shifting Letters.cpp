class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string res = S;
        if (S.empty()) return res;
        int val = 0;
        for (int i = 0; i < S.size(); ++ i) {
            val += shifts[i] % 26;
            if (val > 26) val = val % 26; 
        }
        for (int i = 0; i < S.size(); ++ i) {
            res[i] = (res[i] + val - 'a') % 26 + 'a';
            val = (26 + val - shifts[i] % 26) % 26;
        }
        return res;
    }
};