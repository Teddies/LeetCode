class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        int diff = INT_MAX;
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int max = nums[size - 1] + nums[size - 2] + nums[size - 3];
        int min = nums[0] + nums[1] + nums[2];
        if (target >= max) return max;
        if (target <= min) return min;
        
        for (int i = 0; i < nums.size() - 2; ++ i) {
            int start = i + 1;
            int end = size - 1;
            if (nums[i] + nums[end - 1] + nums[end] < target) {
                if (diff > target - nums[i] - nums[end - 1] - nums[end]) {
                    res = nums[i] + nums[end - 1] + nums[end];
                    diff = target - nums[i] - nums[end - 1] - nums[end];
                }
                continue;
            }
            else {
                while (start < end) {
                    int val = nums[i] + nums[start] + nums[end];
                    if (val < target) {
                        if (diff > target - val) {
                            res = val;
                            diff = target - val;
                        }
                        start ++;
                    }
                    else if (val > target) {
                        if (diff > val - target) {
                            res = val;
                            diff = val - target;
                        }
                        end --;
                    }
                    else return target;
                }
            }
        }
        return res;
    }
};
