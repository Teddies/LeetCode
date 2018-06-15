class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag = 1, val = 0;
        for (int i = s.size() - 1; i >= 0; -- i) {
            if (s[i] != ' ') {
                flag = 0;
                val ++;
            }
            else {
                if (flag == 0) return val;
            }
        }
        return val;
    }
};