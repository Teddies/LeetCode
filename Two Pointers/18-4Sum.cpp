class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums, int target) {
        vector<vector<int>> res;
        if (nums.size() == 3) {
            if (nums[0] + nums[1] + nums[2] == target)
                res.push_back(nums);
            return res;
        }
        for (int i = 0; i <= nums.size() - 3; ++ i) {
            int front = i + 1;
            int back = nums.size() - 1;
            int n = nums[i];
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            while (front < back) {
                if (nums[front] + nums[back] < target - n) {
                    front ++;
                }
                else if (nums[front] + nums[back] > target - n) {
                    back --;
                }
                else { 
                    vector<int> v(3, 0);
                    v[0] = n;
                    v[1] = nums[front];
                    v[2] = nums[back];
                    res.push_back(v);
                    while (front < back && nums[front] == nums[++ front]) continue;
                    while (front < back && nums[back] == nums[-- back]) continue;
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        if (nums.size() == 4) {
            if (nums[0] + nums[1] + nums[2] + nums[3] == target)
                res.push_back(nums);
            return res;
        }
        for (int i = 0; i <= nums.size() - 4; ++ i) {
            int n = nums[i];
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            vector<int> v(nums.begin() + i + 1, nums.end());
            vector<vector<int>> vec = threeSum(v, target - n);
            if (!vec.empty()) {
                for (int j = 0; j < vec.size(); ++ j) {
                    vec[j].push_back(n);
                    res.push_back(vec[j]);
                }
            }
        }
        return res;
    }
};