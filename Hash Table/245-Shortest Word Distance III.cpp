class Solution {
public:
    unordered_map<string, vector<int>> hash;
    
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        for (int i = 0; i < words.size(); ++ i) {
            hash[words[i]].push_back(i);
        }
        int res = INT_MAX;
        if (word1 != word2) {
            vector<int> v1 = hash[word1];
            vector<int> v2 = hash[word2];
            int n = v1.size(), m = v2.size();
            if (n < m) {
                for (int i = 0; i < n; ++ i) {
                    int val = binary(v1[i], v2);
                    res = min(res, val);
                }
            }
            else {
                for (int i = 0; i < m; ++ i) {
                    int val = binary(v2[i], v1);
                    res = min(res, val);
                }
            }
        }
        else {
            vector<int> v = hash[word1];
            for (int i = 0; i < v.size() - 1; ++ i) {
                res = min(v[i + 1] - v[i], res);
            }
        }
        return res;
    }

private:
    int binary(int n, vector<int>& v) {
        int start = 0, end = v.size() - 1;
        while (start + 1 < end) {
            int middle = start + (end - start) / 2;
            if (n < v[middle]) end = middle;
            else start = middle;          
        }
        return min(abs(n - v[start]), abs(v[end] - n));
    }
};