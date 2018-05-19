// Very classical backtracking problem
// Similar methods with the "combination" problem or "subsets" problem
// Example of rewrite the set operator

class Solution {
public:
    
    // Set operator rewrite
    struct Comp {
        vector<int> v1;
        bool operator < (const Comp& c) const {
            vector<int> v2 = c.v1;
            int size = min(v1.size(), v2.size()); 
            for (int i = 0; i < size; ++ i) {
                if (v1[i] < v2[i]) return true;
                else if (v1[i] > v2[i]) return false;
            }
            if (v1.size() < v2.size()) return true;
            else return false;
        }
    };
    
    set<Comp> s;
    
    void findSub(vector<int>& nums, vector<int> v, int index) {
    	// Add the results into the set
        if (v.size() > 1) {
            Comp c;
            c.v1 = v;
            s.insert(c);
        }
        // Use recursion to give combinations of all the possible results
        for (int i = index; i < nums.size(); ++ i) {
            if (v.empty() || v.back() <= nums[i]) {
                v.push_back(nums[i]);
                findSub(nums, v, i + 1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        findSub(nums, v, 0);
        vector<vector<int>> res;
        set<Comp>::iterator it = s.begin();
        while (it != s.end()) {
            res.push_back(it->v1);
            it ++;
        }
        return res;
    }
};