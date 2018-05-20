// Method 1: Using STL set
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

// Method 2: Without using STL set
class Solution {
public:
    unordered_map<int, vector<vector<int>>> hash;
    
    bool judgeRepeat(vector<int> v, int repeat, int val) {
        if (repeat > 0 && v.empty()) return false;
        for (int i = 0; i < repeat; ++ i) {
            if (v[i] != val) return false;
        }
        return true;
    }
    
    vector<vector<int>> findSub(vector<int>& nums, int index, int& repeat) {
        if (hash.find(index) != hash.end()) return hash[index];
        vector<vector<int>> result;
        if (index == nums.size() - 1) {
            vector<vector<int>> vec;
            vector<int> v;
            vec.push_back(v);
            v.push_back(nums[index]);
            vec.push_back(v);
            hash[index] = vec;
            return vec;
        }
        else {
            if (nums[index] == nums[index + 1]) {
                vector<vector<int>> res = findSub(nums, index + 1, repeat);
                result = res;
                repeat ++;
                for (int i = 0; i < res.size(); ++ i) {
                    if (judgeRepeat(res[i], repeat, nums[index])) {
                        vector<int> v = res[i];
                        v.insert(v.begin(), nums[index]);
                        result.push_back(v);
                    }
                }
            }
            else {
                repeat = 0;
                vector<vector<int>> res = findSub(nums, index + 1, repeat);
                result = res;
                repeat = 0;
                for (int i = 0; i < res.size(); ++ i) {
                    vector<int> v = res[i];
                    v.insert(v.begin(), nums[index]);
                    result.push_back(v);
                }
            }
        }
        hash.clear();
        hash[index] = result;
        return result;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int repeat = 0;
        vector<vector<int>> result = findSub(nums, 0, repeat);
        return result;
    }
};