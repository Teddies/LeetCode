// Advanced version
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        double t = myPow(x, n / 2);
        if (n % 2)
            return n < 0 ? 1.0 / x * t * t : x * t * t;
        else
            return t * t;
    }
};

// My version
class Solution {

public:

    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (x == -1) {
            if (n % 2 == 0) return 1;
            return -1;
        }
        if (n == 0) return 1;
        if (n < 0) {
            if (n == INT_MIN) {
                return 0;
            }
            return 1 / myPow(x, (-1) * n);
        }
        int i = 1;
        double res = x;
        while (i * 2 <= n) {
            res *= res;
            i *= 2;
            if (res == 0) return 0;
        }
        if (i * 2 - n < n - i) {
            res *= res;
            res *= myPow(x, n - i * 2);
        }
        else res *= myPow(x, n - i);
        return res;
    }
};


