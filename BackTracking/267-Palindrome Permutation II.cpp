class Solution {
public:
    set<string> permutation(string str) {
        set<string> s;
        if (str.size() == 1) {
            s.insert(str);
            return s;
        }
        if (str.size() == 2) {
            s.insert(str);
            reverse(str.begin(), str.end());
            s.insert(str);
            return s;
        }
        else {
            set<string> rs = permutation(str.substr(1, str.size() - 1));
            set<string>::iterator it = rs.begin();
            while (it != rs.end()) {
                char c = str[0];
                for (int i = 0; i <= (*it).size(); ++ i) {
                    string temp = *it;
                    temp.insert(temp.begin() + i, c);
                    s.insert(temp);
                }
                it ++;
            }
            return s;
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        if (s.size() <= 1) {
            res.push_back(s);
            return res;
        }
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); ++ i) {
            hash[s[i]] ++;
        }
        unordered_map<char, int>::iterator it = hash.begin();
        string str;
        string center = "";
        if (s.size() % 2 == 0) {
            while (it != hash.end()) {
                if (it->second % 2 == 1) return res;
                for (int i = 0; i < it->second / 2; ++ i) str.push_back(it->first);
                it ++;
            }
        }
        else {
            while (it != hash.end()) {
                if (it->second % 2 == 1) {
                    if (center != "") return res;
                    else center.push_back(it->first);
                }
                for (int i = 0; i < it->second / 2; ++ i) str.push_back(it->first); 
                it ++;
            }
        }
        set<string> mySet = permutation(str);
        set<string>::iterator iter = mySet.begin();
        while (iter != mySet.end()) {
            str = *iter;
            reverse(str.begin(), str.end());
            if (s.size() / 2 == 0) res.push_back(*iter + str);
            else res.push_back(*iter + center + str);
            iter ++;
        }
        return res;
    } 
};