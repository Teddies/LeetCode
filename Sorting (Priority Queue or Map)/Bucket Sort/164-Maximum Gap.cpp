class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int res = 0;
        if (nums.empty() || nums.size() < 2) return res;
        if (nums.size() == 2) return nums.back() - nums.front();
        
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < nums.size(); ++ i) {
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
        }
        if (mini == maxi) return 0;
        
        int bucketNum = (int)nums.size() - 1;
        int interval = ceil((double)(maxi - mini) / bucketNum);
        bucketNum = (maxi - mini) / interval + 1;
        vector<int> intervalMax(bucketNum, INT_MIN);
        vector<int> intervalMin(bucketNum, INT_MAX);

        for (int i = 0; i < nums.size(); ++ i) {
            int bucketID = (nums[i] - mini) / interval;
            intervalMax[bucketID] = max(intervalMax[bucketID], nums[i]);
            intervalMin[bucketID] = min(intervalMin[bucketID], nums[i]); 
        }
        
        int last = intervalMax[0];
        for (int i = 1; i < bucketNum; ++ i) {
            if (intervalMin[i] != INT_MAX) {
                res = max(res, intervalMin[i] - last);
                last = intervalMax[i];
            }
        }
        return res;
    }
};