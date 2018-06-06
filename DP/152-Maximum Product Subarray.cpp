// Very classical problem
// Negative elements may cause the current minimum value to be maximum value
// or maximum value converts to minimum value
// 0 may cause the current maximum value to be the current single element
// So we need to maintain 2 variables here: maximum value to the current element,
// and minimum value to the current element.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int minToCurr = nums[0];
        int maxToCurr = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            int n = minToCurr;
            minToCurr = min(min(minToCurr * nums[i], maxToCurr * nums[i]), nums[i]);
            maxToCurr = max(max(n * nums[i], maxToCurr * nums[i]), nums[i]);
            res = max(maxToCurr, res);
        }
        return res;
    }
};