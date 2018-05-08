class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int start = 0, end = nums.size() - 1;
        int middle = start + (end - start) / 2;
        while (start + 1 < end) {
            if (nums[middle] > target) end = middle;
            else if (nums[middle] < target) start = middle;
            else return middle;
            middle = start + (end - start) / 2;
        }
        if (nums[start] == target) return start;
        else if (nums[end] == target) return end;
        else return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return target == nums[0] ? 0 : -1;
        if (nums.back() > nums.front()) {
            // Sorted
            return binarySearch(nums, target);
        }
        else {
            int start = 0, end = nums.size() - 1;
            int middle = start + (end - start) / 2;
            int pivot;
            while (start + 1 < end) {
                if (nums[middle] > nums[start]) start = middle;
                else {
                    if (middle - 1 >= 0 && nums[middle - 1] > nums[middle]) {
                        pivot = middle;
                        break;
                    }
                    else end = middle;
                }
                middle = start + (end - start) / 2;
            }
            if (start + 1 == end) pivot = end;
            if (target < nums[0]) {
                vector<int> v(nums.begin() + pivot, nums.end());
                int res = binarySearch(v, target);
                if (res == -1) return -1;
                else return pivot + res;
            }
            else {
                vector<int> v(nums.begin(), nums.begin() + pivot);
                return binarySearch(v, target);
            }
        }
    }
};
