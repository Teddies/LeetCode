class Solution {
public:
    static bool greater(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 != len2) {
            if (len1 < len2) {
                string str = s2;
                if (s1 == str.substr(0, len1)) {
                    string ss1 = s1 + s2;
                    string ss2 = s2 + s1;
                    return ss1 > ss2;
                }
            }
            else {
                string str = s1;
                if (s2 == str.substr(0, len2)) {
                    string ss1 = s1 + s2;
                    string ss2 = s2 + s1;
                    return ss1 > ss2;
                }
            }
        }
        return s1 > s2;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int i = 0; i < nums.size(); ++ i) {
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), greater);
        string res = "";
        for (int i = 0; i < nums.size(); ++ i) {
            res += v[i];
        }
        if (res.size() > 1 && res.front() == '0') return "0";
        return res;
    }
};