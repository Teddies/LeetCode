class Solution {
public:
    bool checkPeak(vector<int>& nums, int index) {
        if (index == 0 && nums[1] < nums[0]) return true;
        if (index == nums.size() - 1 && nums[index - 1] < nums[index]) return true;
        if (nums[index - 1] < nums[index] && nums[index + 1] < nums[index]) return true;
        return false;
    }
    
    int findPeakElement(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return 0;
        int start = 0, end = nums.size() - 1;
        int middle = start + (end - start) / 2;
        if (checkPeak(nums, start)) return start;
        if (checkPeak(nums, end)) return end;
        if (checkPeak(nums, middle)) return middle;
        while (start + 1 < end) {
            if (nums[start] >= nums[middle] && nums[middle] > nums[end]) {
                end = middle;
            }
            else if (nums[start] < nums[middle] && nums[middle] > nums[end] && nums[middle - 1] > nums[middle]) {
                end = middle;
            }
            else start = middle;
            middle = start + (end - start) / 2;
            if (checkPeak(nums, middle)) return middle;
        }
        if (checkPeak(nums, start)) return start;
        else return middle;
    }
};