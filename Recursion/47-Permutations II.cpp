class Solution {
public:
    struct vComp {
        vector<int> v1;
        bool operator< (const vComp &vc) const {
            int size = min(v1.size(), vc.v1.size());
            for (int i = 0; i < size; ++ i) {
                if (v1[i] < vc.v1[i]) return true;
                else if (v1[i] > vc.v1[i]) return false;
            }
            if (v1.size() < vc.v1.size()) return true;
            else return false;
        }
    };
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1 || nums.empty()) {
            res.push_back(nums);
            return res;
        }
        if (nums.size() == 2) {
            res.push_back(nums);
            if (nums[0] != nums[1]) {
                int t = nums[0];
                nums[0] = nums[1];
                nums[1] = t;
                res.push_back(nums);
            }
            return res;
        }
        
        set<vComp> s;
        vector<int> num(nums.begin() + 1, nums.end());
        vector<vector<int>> v = permuteUnique(num);
        for (int i = 0; i < v.size(); ++ i) {
            for (int j = 0; j <= v[i].size(); ++ j) {
                if (j >= 1 && v[i][j - 1] == v[i][j] && v[i][j] == nums[0]) 
                    continue;
                vector<int> vec;
                for (int k = 0; k < j; ++ k) {
                    vec.push_back(v[i][k]);
                }
                vec.push_back(nums[0]);
                for (int k = j; k < v[i].size(); ++ k) {
                    vec.push_back(v[i][k]);
                }
                vComp vc;
                vc.v1 = vec;
                s.insert(vc);
            }
        }
        
        set<vComp>::iterator it = s.begin();
        while (it != s.end()) {
            res.push_back(it->v1);
            it ++;
        }
        
        return res;
    }
};