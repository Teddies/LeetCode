class Solution {
public:
    string recursion(int n, int k, int m, string& vec) {
        if (k == 0) {
            reverse(vec.begin(), vec.end());
            return vec;
        }
        if (k == 1) return vec;
        m /= n;
        string res;
        if (k % m == 0) {
            res.push_back(vec[k / m - 1]);
            vec.erase(vec.begin() + k / m - 1);
        }
        else {
            res.push_back(vec[k / m]);
            vec.erase(vec.begin() + k / m);
        }
        res += recursion(n - 1, k - k / m * m, m, vec);
        return res;
    }
    
    string getPermutation(int n, int k) {
        string vec;
        int m = 1;
        for (int i = 1; i <= n; ++ i) {
            vec.push_back(i + '0');
            m *= i;
        }
        return recursion(n, k, m, vec);
    }
};