class Solution {
public:
    int reverse(int x) {
        if (x < 10 && x > -10) return x;
        if (x == INT_MIN) return 0;
        string rev = to_string(abs(x));
        std::reverse(rev.begin(), rev.end());
        string ubound = to_string(INT_MAX);
        string lbound = to_string(INT_MIN);
        if (x > 0) { 
            if (rev.size() == ubound.size() && rev > ubound) return 0;
            else return atoi(rev.c_str());
        }
        else {
            rev = "-" + rev;
            if (rev.size() == lbound.size() && rev > lbound) return 0;
            else return atoi(rev.c_str());
        }
    }
};