// Method 1: return vector

class Solution {
public:
    bool isPalindrome(string& s) {
        if (s.size() == 1) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i ++;
            j --;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) {
            vector<string> v;
            res.push_back(v);
            return res;
        }
        if (s.size() == 1) {
            vector<string> v;
            v.push_back(s);
            res.push_back(v);
            return res;
        }
         for (int i = 1; i < s.size(); ++ i) {
             string str = s.substr(0, i);
             if (isPalindrome(str)) {
                 vector<vector<string>> vec = partition(s.substr(i, s.size() - i)); 
                 for (int j = 0; j < vec.size(); ++ j) {
                     vec[j].insert(vec[j].begin(), str);
                     res.push_back(vec[j]);
                 }
             }
         }
        if (isPalindrome(s)) {
            vector<string> v;
            v.push_back(s);
            res.push_back(v);
        } 
        return res;
    }
};

// Method 2: Using void function and reference of the vector
// Improve the performance with the standard backtracking 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};