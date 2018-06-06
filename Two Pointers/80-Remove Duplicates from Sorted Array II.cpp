class Solution {
public:
    void swap(int i, int j, vector<int>& nums) {
        int n = nums[j];
        nums[j] = nums[i];
        nums[i] = n;
    }
    
    // Basic idea: swap the elements that are going to be deleted
    // to the end of the vector and remove them together at last
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int start = -1, end = -1, val = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] == val) {
                count ++;
                if (count > 2) {
                    if (start == -1) {
                        start = i;
                        end = i;
                    }
                    else end = i;
                }
                else if (start != -1) {
                    swap(start, i, nums);
                    start ++;
                    end ++;
                }
            }
            else {
                val = nums[i];
                count = 1;
                if (start != -1) {
                    swap(start, i, nums);
                    start ++;
                    end ++;
                }
            }
        }
        if (start != -1) nums.erase(nums.begin() + start, nums.end());
        return nums.size();
    }
};