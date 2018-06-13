// Method 1: DP
// O(n) time complexity and O(n) space complexity
// Runtime: 4ms
class Solution {
public:
    int numDecodings(string s) {
        vector<int> res(s.size(), 0);
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        res[0] = 1;
        for (int i = 1; i < s.size(); ++ i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') res[i] = i == 1 ? 1 : res[i - 2];
                else return 0;
            }
            else {
                if (s[i - 1] == '0' || s[i - 1] >= '3') res[i] = res[i - 1];
                else if (s[i - 1] == '1') res[i] = i == 1 ? 2 : res[i - 1] + res[i - 2];
                else {
                    if (s[i] <= '6') res[i] = i == 1 ? 2 : res[i - 1] + res[i - 2];
                    else res[i] = res[i - 1];
                }
            }
        }
        return res.back();
    }
};

// Method 2: Recursion
// O(n) time complexity and O(n^2) space complexity
// Runtime: 933ms
class Solution {
public:
    int recursion(int index, string& s) {
        if (s[index] == '0') return 0;
        if (index >= s.size() - 1) return 1;
        if (s[index] > '2' && s[index + 1] == '0') return 0;
        if (s[index + 1] == '0') return recursion(index + 2, s);
        if (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6') return recursion(index + 1, s) + recursion(index + 2, s);
        return recursion(index + 1, s);
    }
    
    int numDecodings(string s) {
        return recursion(0, s);
    }
};