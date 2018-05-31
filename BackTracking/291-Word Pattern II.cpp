class Solution {
public:
    // Check each pattern character with its string
    unordered_map<char, string> hash;
    // Check the string whether has been assigned to a pattern (reverse hash)
    unordered_map<string, char> rhash;
    
    bool findSub(int index, string& str, string& pattern) {
        // If the substring is overflow, return false
        if (index == str.size()) return false;
        // Termination condition
        if (pattern.size() == 1) {
            string substr = str.substr(index, str.size() - index);
            if (hash.find(pattern[0]) == hash.end()) {
                if (rhash.find(substr) == rhash.end()) return true;
                else return false;
            }
            else if (hash[pattern[0]] == substr) return true;
            else return false;
        }
        // Recursion
        for (int i = index; i < str.size(); ++ i) {
            char c = pattern[0];
            string subpattern = pattern.substr(1, pattern.size() - 1);
            // If this is a new pattern character, add it into the hash table and start recursion
            if (hash.find(c) == hash.end()) {
                string substr = str.substr(index, i - index + 1);
                if (rhash.find(substr) != rhash.end()) continue;
                hash[c] = substr;
                rhash[substr] = c;
                // Start recursion, if true, end, else, return and backtracking
                if (findSub(i + 1, str, subpattern)) return true;
                else {
                    // backtracking
                    hash.erase(c);
                    rhash.erase(substr);
                }
            }
            // If the pattern character has occurred before, 
            // then directly return whether the substring is valid (no need to loop)
            else {
                string s = hash[c];
                if (str.substr(index, s.size()) != s) return false;
                else {
                    i += s.size();
                    return findSub(i, str, subpattern);
                }
            }
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        if (str.empty() && pattern.empty()) return true;
        if (str.empty() && !pattern.empty()) return false;
        if (pattern.empty()) return false;
        return findSub(0, str, pattern);
    }
};