class Solution {
public:
    void findSub(int index, int k, int n, vector<int>& v, vector<int>& temp, vector<vector<int>>& res) {
        for (int i = index; i < v.size(); ++ i){
            if (k == 1 && v[i] == n) {
                temp.push_back(v[i]);
                res.push_back(temp);
                temp.pop_back();
                return;
            }
            if (v[i] >= n) return;
            temp.push_back(v[i]);
            findSub(i + 1, k - 1, n - v[i], v, temp, res);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k > 9 || n > 45 || k < 1 || n < 1) return res;
        vector<int> v, temp;
        for (int i = 1; i < 10; ++ i) {
            v.push_back(i);
        }
        findSub(0, k, n, v, temp, res);
        return res;
    }
};