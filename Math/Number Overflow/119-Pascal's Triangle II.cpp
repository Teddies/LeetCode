class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> res;
        res.push_back(1);
        if (numRows == 0) return res;
        for (int i = 1; i <= numRows / 2; ++ i) {
            long long int n = (long long int)res.back() * (numRows - i + 1) / i;
            res.push_back((int)n);
        }
        for (int i = numRows / 2 + 1; i < numRows; ++ i) {
            res.push_back(res[numRows - i]);
        }  
        res.push_back(1);
        return res;
    }
};