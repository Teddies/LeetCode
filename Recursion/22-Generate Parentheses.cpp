class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n < 1) return res;
        if (n == 1) {
            res.push_back("()");
            return res;
        }
        vector<string> v = generateParenthesis(n - 1);
        for (int i = 0; i < v.size(); ++ i) {
            string s = v[i];
            s = "(" + s;
            int left = 0;
            for (int j = 0; j < s.size(); ++ j) {
                if (s[j] == '(') left ++;
                else left --;
                if (left == 1) {
                    string str = s.substr(0, j + 1) + ")" + s.substr(j + 1, s.size() - j - 1);
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};
