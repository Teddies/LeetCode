class Solution {
public:
    
    int count(vector<int>& ages) {
        int slow = 0, fast = 1;
        int res = 0;
        int repeat = 0;
        if (ages[0] == ages[1]) repeat ++;
        while (fast < ages.size()) {
            if (ages[slow] > ages[fast] * 0.5 + 7) {
                res += fast - slow + repeat;
                fast ++;
                if (ages[fast - 1] == ages[fast]) repeat ++;
                else repeat = 0;
            }
            else {
                slow ++;
                if (slow == fast) {
                    fast ++;
                    if (ages[fast - 1] == ages[fast]) repeat ++;
                    else repeat = 0;
                }
            }
        }
        return res;
    }
    
    int numFriendRequests(vector<int>& ages) {
        if (ages.empty()) return 0;
        sort(ages.begin(), ages.end());
        int res = 0;
        return count(ages);
    } 
};