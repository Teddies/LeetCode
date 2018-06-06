class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        if (nums.empty()) return 0;
        if (nums.size() == 1) {
            if (nums[0] >= s) return 1;
            else return 0;
        }
        int slow = 0, fast = 1;
        int sum = nums[0];
        if (sum >= s) return 1;
        while (fast < nums.size()) {
            if (nums[fast] >= s) return 1;
            sum += nums[fast];
            while (sum >= s) {
                res = min(res, fast - slow + 1);
                sum -= nums[slow];
                slow ++;
            }
            fast ++;
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};