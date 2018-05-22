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
            return v.size() < c.v.size();
        }
    };
    
    set<Comp> s;
    
    void findSub(vector<int>& candidates, int index, vector<int>& temp, int target) {
        for (int i = index; i < candidates.size(); ++ i){
            if (candidates[i] > target) return;
            else if (candidates[i] == target) {
                temp.push_back(candidates[i]);
                Comp c;
                c.v = temp;
                s.insert(c);
                temp.pop_back();
                return;
            }
            else {
                temp.push_back(candidates[i]);
                findSub(candidates, i + 1, temp, target - candidates[i]);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findSub(candidates, 0, temp, target);
        
        vector<vector<int>> res;
        set<Comp>::iterator it = s.begin();
        while (it != s.end()) {
            res.push_back(it->v);
            it ++;
        }
        return res;
    }
};