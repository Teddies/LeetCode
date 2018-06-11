class Solution {
public:
    class MonotonicQueue {
    public:
        void push(int n) {
            while (!dq.empty() && dq.back() < n) {
                dq.pop_back();
            }
            dq.push_back(n);
        }
        
        void pop() {
            dq.pop_front();
        }
        
        int getMax() {
            return dq.front();
        }
        
        bool empty() {
            return dq.empty();
        }
        
    private:
        deque<int> dq;
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue mq;
        for (int i = 0; i < nums.size(); ++ i) {
            if (i - k + 1 <= 0) {
                mq.push(nums[i]);
            }   
            else {
                res.push_back(mq.getMax());
                if (mq.getMax() == nums[i - k]) mq.pop();
                mq.push(nums[i]);
            }
        }
        if (!mq.empty()) res.push_back(mq.getMax());
        return res;
    }
};