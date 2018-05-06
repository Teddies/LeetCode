class Solution {
public:
    int calculate(int &numerator, int denominator) {
        int times = 1;
        int n = numerator;
        int res = 0;
        while (times < 10) {
            if (denominator > 0) numerator -= denominator;
            else numerator += denominator;
            res ++;
            numerator += n;
            times ++;
            while (numerator < 0 && times < 10) {
                numerator += n;
                times ++;
            } 
        }
        if (numerator < 0) {
            res --;
            if (denominator > 0) numerator += denominator;
            else numerator -= denominator;
        }
        return res;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> hash;
        string res;
        if (numerator == INT_MIN && denominator == -1) {
            res = to_string(INT_MAX);
            res.back() += 1;
            return res;
        }
        if (numerator < 0 && denominator > 0) {
            res = "-";
            if (numerator != INT_MIN) numerator *= (-1);
        }
        else if (numerator > 0 && denominator < 0) {
            res = "-";
            denominator *= (-1);
        }
        else if (numerator < 0 && denominator < 0) { 
            if (numerator != INT_MIN) numerator *= (-1);
            if (numerator != INT_MIN) denominator *= (-1);
        }
        int n = numerator / denominator;
        if (n * denominator == numerator) {
            return to_string(n);
        }
        res += to_string(n) + ".";
        numerator -= n * denominator;
        hash[numerator] = res.size();
        while (true) {
            // Overflow
            int n = numerator * 10 / denominator;
            if (numerator * 10 / numerator == 10) {
                numerator = numerator * 10 - n * denominator;
            }
            else {
                n = calculate(numerator, denominator);
            }
            res += to_string(n);
            
            if (numerator == 0) {
                if (numerator == INT_MIN) {
                    if (res[0] == '-') {
                        string ss = res.substr(1, res.size() - 1);
                        return ss;
                    }
                    else {
                        string ss = "-" + res;
                        return ss;
                    }
                }
                return res;
            }
            if (hash.find(numerator) != hash.end()) {
                res += ")";
                string s = res.substr(0, hash[numerator]);
                s += "(";
                s += res.substr(hash[numerator], res.size() - hash[numerator]);
                return s;
            }
            else hash[numerator] = res.size();
        }
    }
};