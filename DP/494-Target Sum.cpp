// So naive with high complexity
// Need improvements
class Solution {
public:
    int count(vector<int>& nums, int S, int sum) {
        if (S > sum || S < (-1) * sum) return 0;
        if (nums.size() == 1) {
            if (S == 0 && nums[0] == 0) return 2;
            if (S == nums[0] || S == nums[0] * (-1)) return 1;
            return 0;
        }
        vector<int> v(nums.begin(), nums.end() - 1);
        int val = nums.back();
        return count(v, S - val, sum - val) + count(v, S + val, sum - val);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return count(nums, S, sum);
    }
};