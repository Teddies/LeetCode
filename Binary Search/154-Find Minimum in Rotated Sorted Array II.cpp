class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1 || nums[0] < nums.back()) return nums[0];
        int start = 0, end = nums.size() - 1;
        int middle = start + (end - start) / 2;
        while (start + 1 < end) {
            if (nums[middle] > nums[start])
                start = middle;
            else if (nums[middle] < nums[start])
                end = middle;
            else {
                if (nums[middle] == nums[end]) {
                    vector<int> v1, v2;
                    for (int i = start; i < middle; ++ i)
                        v1.push_back(nums[i]);
                    for (int i = middle; i <= end; ++ i)
                        v2.push_back(nums[i]);
                    return min(findMin(v1), findMin(v2));
                }
                else if (nums[middle] < nums[end])
                    end = middle;
                else
                    start = middle;
            }
            middle = start + (end - start) / 2;
        }
        return min(nums[start], nums[end]);
    }
};