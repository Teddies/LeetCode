class Solution {
public:
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i ++;
            j --;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 1; -- i) {
            if (nums[i] > nums[i - 1]) {
                for (int j = nums.size() - 1; j >= i; -- j) {
                    if (nums[j] > nums[i - 1]) {
                        int temp = nums[j];
                        nums[j] = nums[i - 1];
                        nums[i - 1] = temp;
                        break;
                    }
                }
                reverse(nums, i);
                return;
            }
        }
        reverse(nums, 0);
    }
};