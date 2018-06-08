class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        if (n == 3) return "21";
        if (n == 4) return "1211";
        string str = countAndSay(n - 1);
        int count = 1;
        char val = str[0];
        string res;
        for (int i = 1; i < str.size(); ++ i) {
            if (str[i] != str[i - 1]) {
                res.push_back(count + '0');
                res.push_back(str[i - 1]);
                count = 1;
            }
            else count ++;
        }
        // Don`t forget below after getting out of the loop
        res.push_back(count + '0');
        res.push_back(str.back());
        return res;
    }
};