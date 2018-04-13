class Solution {
public:
	// First step: Count the numbers of invalid parentheses of left and right each
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
    
    // Second step: Write a function to judge whether the string is valid
    // Notice there might be letters within the string
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push('(');
            }
            // Cannot use else because there might have letters
            if (c == ')') {
                if (st.empty()) 
                    return false;
                else 
                    st.pop();
            }
        }
        return st.empty();
    }
    
    // The left and right values are used for the recursion
    // The start value is used to record where to start within the string
    // The character before the start value (start index in the vector)
    // has already been discussed in the previous cases, so during the 
    // recursion we always discuss the characters after the start index
    vector<string> DFS(string s, int left, int right, int start) {
        vector<string> res;
        // Actually this is not needed, but write here to make it clear
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        // Recursion basic condition (also the terminate condition)
        if (left == 0 && right == 0 && isValid(s)) {
            res.push_back(s);
            return res;
        }
        for (int i = start; i < s.size(); ++ i) {
            vector<string> v;
            // Avoid the repeatitive results
            // Reduce the branches of the tree structure to improve performance
            // Continuous same parentheses may cause repeatitive results
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
