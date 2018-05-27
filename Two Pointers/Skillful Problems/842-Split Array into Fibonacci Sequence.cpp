class Solution {
public:
    bool check(int first, int second, string S, vector<int>& res) {
        string str = to_string(first + second);
        if (S == str) {
            res.push_back(first + second);
            return true;
        }
        if (S.size() < str.size() || (S.size() == str.size() && str != S)) return false;
        if (S.substr(0, str.size()) == str) {
            first = second;
            second = atoi(str.c_str());
            res.push_back(second);
            return check(first, second, S.substr(str.size(), S.size() - str.size()), res);
        }
        else return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        int first, second;
        for (int i = 1; i <= S.size() / 2; ++ i) {
            // 01 is not allowed to represent 1
            if (S[0] == '0') {
                if (i > 1) break;
                first = 0;
            }
            else first = atoi(S.substr(0, i).c_str());
            for (int j = i; j < (S.size() + i) / 2; ++ j) {
                res.clear();
                if (S[i] == '0') {
                    if (j > i) break;
                    second = 0;
                }
                else second = atoi(S.substr(i, j - i + 1).c_str());
                res.push_back(first);
                res.push_back(second); 
                if (check(first, second, S.substr(j + 1, S.size() - j), res)) return res;
            }
        }
        res.clear();
        return res;
    }
};