class Solution {
public:
    vector<string> DFS(string& s, int num) {
        vector<string> res;
        if (s.size() < num) return res;
        if (num == 1) {
            // The predicate s.size() > 3 is important
            // since it is possible for atoi(s.c_str()) to overflow
            if (s.size() > 3 || atoi(s.c_str()) > 255 || (s.size() > 1 && s[0] == '0')) return res;
            res.push_back(s);
            return res;
        }

        // Notice that the for loop termination predicate is min((int)s.size(), 3)
        // since it is possibly less than 3
        for (int i = 0; i < min((int)s.size(), 3); ++ i) {
            string substr = s.substr(0, i + 1);
            if (atoi(substr.c_str()) > 255 || (i > 0 && s[0] == '0')) return res;
            string str = s.substr(i + 1, s.size() - i - 1);
            vector<string> v = DFS(str, num - 1);
            
            for (int j = 0; j < v.size(); ++ j) {
                string ss = substr + "." + v[j];
                res.push_back(ss);
            }
        }
        return res;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        res = DFS(s, 4);
        return res;
    }
};