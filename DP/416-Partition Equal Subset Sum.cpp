class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) return true;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        int max = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            for (int j = max; j >= 0; -- j) {
                if (dp[j]) dp[j + nums[i]] = 1;
            }
            max += nums[i];
            if (dp[sum / 2]) return true;
        }
        return false;
    }
};