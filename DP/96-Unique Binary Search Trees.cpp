class Solution {
public:
    unordered_map<int, int> hash;
    Solution() {
        hash[1] = 1;
        hash[2] = 2;
        hash[3] = 5;
    }
    
    int numTrees(int n) {
        if (n < 1) return 0;
        if (hash.find(n) != hash.end()) return hash[n];
        int res = 2 * numTrees(n - 1);
        for (int i = n - 2; i >= 1; -- i) {
            res += numTrees(n - 1 - i) * numTrees(i);
        }
        hash[n] = res;
        return res;
    }
};