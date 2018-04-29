class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 1) return res;
        int pointer = 0;
        while (pointer < nums.size()) {
            if (nums[pointer] == -1 || nums[pointer] == pointer + 1) {
                pointer ++;
            }
            else {
                int temp = nums[pointer];
                if (nums[temp - 1] == temp) {
                    res.push_back(temp);
                    nums[pointer] = -1;
                }
                else {
                    nums[pointer] = nums[temp - 1];
                    nums[temp - 1] = temp;
                }
            }
        }
        return res;
    }
};