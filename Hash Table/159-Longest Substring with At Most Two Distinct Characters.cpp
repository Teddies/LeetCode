class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> hash;
        int size = 0, pointer = 0, res = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (hash[s[i]] == 0) size ++;
            hash[s[i]] ++;
            while (size > 2) {
                hash[s[pointer]] --;
                if (hash[s[pointer]] == 0) size --;
                pointer ++;
            }
            res = max(res, i - pointer + 1);
        }
        return res;
    }
};