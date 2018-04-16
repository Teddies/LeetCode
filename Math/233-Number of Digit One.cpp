class Solution {
public:
    int countDigits(int n) {
        int res = 1;
        while (n / 10 != 0) {
            n /= 10;
            res ++;
        }
        return res;
    }
    
    int lessDigitCount(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++ i) {
            res += res * 9 + pow(10, (i - 1));
        }
        return res;
    }
    
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n <= 9) return 1;
        int p = countDigits(n);
        int res = lessDigitCount(p - 1);
        int cache = res;
        int m = pow(10, p - 1);
        int d = n % m, q = n / m;
        if (q > 1) {
            res += res + m;
            res += cache * (q - 2) + countDigitOne(d);
        }
        else {
            res += n - m + 1;
            res += countDigitOne(d);
        }
        return res;
    }
};