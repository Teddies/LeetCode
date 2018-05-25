class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int middle = start + (end - start) / 2;
        // Be careful with the 0 index
        if (target <= nums[0]) return 0;
        else if (target > nums.back()) return nums.size();
        else if (target == nums.back()) return end;
        while (start + 1 < end){
            if (nums[middle] == target) return middle;
            else if (nums[middle] > target) end = middle;
            else start = middle;
            middle = start + (end - start) / 2;
        }
        if (nums[start] > target) return start - 1;
        else if (nums[start] == target) return start;
        else if (nums[end] < target) return end + 1;
        else if (nums[end] == target) return end;
        else return start + 1;
    }
};