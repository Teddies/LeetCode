class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); ++ i) {
            if (hash.find(target - nums[i]) != hash.end()) {
                res.push_back(hash.find(target - nums[i])->second);
                res.push_back(i);
                return res;
            }
            else {
                hash[nums[i]] = i;
            }
        }
        return res;
    }
};