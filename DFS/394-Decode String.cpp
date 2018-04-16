class Solution {
public:
    string DFS(string &s, int n) {
        string res = "", num = "";
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                res += s[i];
            }
             while (s[i] <= '9' && s[i] >= '0') {
                num += s[i];
                ++ i;
            }
            if (s[i] == '[') {
                int m = atoi(num.c_str());
                num = "";
                string str = "";
                i ++;
                int flag = 1;
                while (flag != 0) {
                    if (s[i] == '[') flag ++;
                    if (s[i] == ']') flag --;
                    str += s[i];
                    ++ i;
                }
                str.pop_back();
                -- i;
                res += DFS(str, m);
            }
        }
        string str = res;
        for (int i = 1; i < n; ++ i) {
            res += str;
        }
        return res;
    }
    
    string decodeString(string s) {
        return DFS(s, 1);
    }
};