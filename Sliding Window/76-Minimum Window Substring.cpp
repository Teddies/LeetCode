class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target, valid;
        unordered_map<char, vector<int>> found;
        queue<int> q;
        string tt;
        for(int i = 0; i < t.size(); ++ i) {
            target[t[i]] ++;
        }
        for (unordered_map<char, int>::iterator it = target.begin(); it != target.end(); it ++) {
            tt.push_back(it->first);
        }
        string res = "";
        int windowSize = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); ++ i) {
            char c = s[i];
            if (flag == 1) { 
                int n = q.front();
                if (target.find(c) != target.end()) {
                    q.push(i);
                    found[c].push_back(i);
                    if (s[n] == s[i]) { 
                        q.pop();
                        found[s[n]].erase(found[s[n]].begin());
                        while (!q.empty()) {
                            n = q.front();
                            if (i - n + 1 < windowSize) {
                                res = s.substr(n, i - n + 1);
                                windowSize = i - n + 1;
                            }
                            if (found[s[n]].size() > target[s[n]]) {
                                found[s[n]].erase(found[s[n]].begin());
                                q.pop();
                            }
                            else break;
                        }
                        windowSize = res.size();
                        if (windowSize == t.size()) return res;
                    }
                }
            }
            else {
                if (target.find(c) != target.end()) {
                    q.push(i);
                    found[c].push_back(i);
                    if ((int)found[c].size() == target[c]) valid[c] = 1;
                    if (valid.size() == tt.size()) {
                        flag = 1;
                        while (!q.empty()) {
                            int n = q.front();
                            res = s.substr(n, i - n + 1);
                            if (found[s[n]].size() > target[s[n]]) {
                                found[s[n]].erase(found[s[n]].begin());
                                q.pop();
                            }
                            else break;
                        }
                        windowSize = res.size();
                        if (windowSize == t.size()) return res;
                    }
                }
            }
        }
        return res;
    }
};