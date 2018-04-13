class Solution {
public:
    void count(string s, int &left, int &right) {
        int l = 0, r = 0;
        left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                l ++;
            }
            if (c == ')') {
                r ++;
            }
            if (r > l) {
                r --;
                right ++;
            }
        }
        left = l - r;
    }
    
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push('(');
            }
            if (c == ')') {
                if (st.empty()) 
                    return false;
                else 
                    st.pop();
            }
        }
        return st.empty();
    }
    
    vector<string> DFS(string s, int left, int right, int start) {
        vector<string> res;
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        if (left == 0 && right == 0 && isValid(s)) {
            res.push_back(s);
            return res;
        }
        for (int i = start; i < s.size(); ++ i) {
            vector<string> v;
            if (i > 0 && s[i - 1] == s[i])
                continue;
            if (left > 0 && s[i] == '(') {
                string temp = s;
                temp.erase(temp.begin() + i);
                v = DFS(temp, left - 1, right, i);
            }
            else if (right > 0 && s[i] == ')') {
                string temp = s;
                temp.erase(temp.begin() + i);
                v = DFS(temp, left, right - 1, i);
            }
            for (int i = 0; i < v.size(); ++ i) {
                res.push_back(v[i]);
            }
        }
        return res;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int left, right;
        count(s, left, right);
        return DFS(s, left, right, 0);
    }
};
