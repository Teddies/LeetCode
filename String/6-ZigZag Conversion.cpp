class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 0) return "";
        if (s.size() <= 2 || numRows == 1) return s;
        if (numRows == 2) {
            string s1 = "", s2 = "";
            for (int i = 0; i < s.size(); ++ i) {
                if (i % 2 == 0) s1.push_back(s[i]);
                else s2.push_back(s[i]);
            }
            return s1 + s2;
        }
        
        int num = 2 * numRows - 2;
        int max = s.size() / num;
        unordered_map<int, string> m;
        for (int i = 0; i < max; ++ i) {
            int start = i * num;
            int end = start + numRows;
            for (int j = start; j < end; ++ j) {
                m[j - start].push_back(s[j]);
            }
            for (int j = end; j < start + num; ++ j) {
                m[numRows - 2 - j + end].push_back(s[j]);
            }
        }
        int start = max * num;
        int i = start;
        while (i < s.size()) {
            if (i - start < numRows) {
                m[i - start].push_back(s[i]);
            }
            else {
                m[numRows - 2 - i + start + numRows].push_back(s[i]);
            }
            i ++;
        }
        string res = "";
        for (int i = 0; i < numRows; ++ i) {
            res += m[i];
        }
        return res;
    }
};