// When using for loop to delete elements
// DO NOT forget "i --"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
                // DO NOT FORGET THE FOLLOWING LINE
                i --;
            }
        }
        return nums.size();
    }
};