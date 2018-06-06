// Put 0 from the beginning
// Put 2 from the end of the list
// Move 1 to the middle

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (nums[i] == 0 && i < j) i ++;
            while (nums[j] == 2 && j > i) j --;
            if (nums[i] == 1 && nums[j] == 1) {
                for (int k = i + 1; k < j; ++ k) {
                    if (nums[k] == 0) {
                        nums[k] = 1;
                        nums[i] = 0;
                        break;
                    }
                    if (nums[k] == 2) {
                        nums[k] = 1;
                        nums[j] = 2;
                        break;
                    }
                    if (k + 1 == j) return;
                }
            }
            else {
                int n = nums[j];
                nums[j] = nums[i];
                nums[i] = n;
            }
            if (i + 1 == j) return;
        }
    }
};