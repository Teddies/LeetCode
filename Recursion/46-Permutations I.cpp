class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty() || nums.size() == 1) {
            res.push_back(nums);
            return res;
        }
        if (nums.size() == 2) {
            res.push_back(nums);
            int t = nums[0];
            nums[0] = nums[1];
            nums[1] = t;
            res.push_back(nums);
            return res;
        }
        vector<int> num(nums.begin() + 1, nums.end());
        vector<vector<int>> v = permute(num);
        for (int i = 0; i < v.size(); ++ i) {
            for (int j = 0; j <= v[i].size(); ++ j) {
                vector<int> vec;
                for (int k = 0; k < j; ++ k) {
                    vec.push_back(v[i][k]);
                }
                vec.push_back(nums[0]);
                for (int k = j; k < v[i].size(); ++ k) {
                    vec.push_back(v[i][k]);
                }
                res.push_back(vec);
            } 
        }
        return res;
    } 
};