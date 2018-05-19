class Solution {
public:
    struct Comp {
        vector<int> v;
        bool operator < (const Comp& c) const {
            int size = min(v.size(), c.v.size());
            for (int i = 0; i < size; ++ i) {
                if (v[i] < c.v[i]) return true;
                else if (v[i] > c.v[i]) return false;
            }
            if (v.size() < c.v.size()) return true;
            return false;
        }
    };
    
    set<Comp> s;
    
    void findSub(vector<int>& nums, vector<int> v, int index) {
        Comp c;
        c.v = v;
        s.insert(c);
        for (int i = index; i < nums.size(); ++ i){
            v.push_back(nums[i]);
            findSub(nums, v, i + 1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        findSub(nums, v, 0);
        vector<vector<int>> res;
        set<Comp>::iterator it = s.begin();
        while (it != s.end()) {
            res.push_back(it->v);
            it ++;
        }
        return res;
    }
};