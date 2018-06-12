class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < richer.size(); ++ i) {
            hash[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> res(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); ++ i) {
            res[i] = dfs(i, hash, res, quiet);
        }
        return res;
    }
    
    int dfs(int n, unordered_map<int, vector<int>>& hash, vector<int>& res, vector<int>& quiet) {
        if (res[n] == -1) {
            res[n] = n;
            vector<int> v = hash[n];
            for (int i = 0; i < v.size(); ++ i) {
                int m = dfs(v[i], hash, res, quiet);
                if (quiet[m] < quiet[res[n]])
                    res[n] = m;
            }
        }
        return res[n];
    }
};