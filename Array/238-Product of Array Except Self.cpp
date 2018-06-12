// O(n) Time Complexity
// O(1) Space Complexity

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        int right = 1;
        res.push_back(1);
        for (int i = 1; i < size; ++ i) {
            res.push_back(res.back() * nums[i - 1]);
        }
        
        for (int i = size - 1; i >= 0; -- i) {
            res[i] *= right; 
            right *= nums[i];
        }
        return res;
    }
};