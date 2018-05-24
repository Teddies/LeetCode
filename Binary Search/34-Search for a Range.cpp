class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int start = 0, end = nums.size() - 1;
        int middle = start + (end - start) / 2;
        int pointer = -1;
        while (start + 1 < end) {
            if (nums[middle] < target) start = middle;
            else if (nums[middle] > target) end = middle;
            else {
                pointer = middle;
                break;
            }
            middle = start + (end - start) / 2;
        }
        if (pointer == -1) {
            if (nums[start] == target) pointer = start;
            else if (nums[end] == target) pointer = end;
            else return res;
        }
        if (nums.back() == target) res[1] = nums.size() - 1;
        else {
            for (int i = pointer; i < nums.size(); ++ i) {
                if (nums[i] != target) {
                    res[1] = i - 1;
                    break;
                }
            }
        }
        if (nums[0] == target) res[0] = 0;
        else {
            for (int i = pointer; i >= 0; -- i) {
                if (nums[i] != target) {
                    res[0] = i + 1;
                    break;
                }
            }
        }
        return res;
    }
};