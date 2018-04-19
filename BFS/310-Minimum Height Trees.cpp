// BFS 
// Remove the leaves round by round
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> tree;
        vector<int> res;
        vector<int>ins(n, 0);
        if (n == 0) return res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        for (int i = 0; i < edges.size(); ++ i) {
            ins[edges[i].first] ++;
            ins[edges[i].second] ++;
            tree[edges[i].first].push_back(edges[i].second);
            tree[edges[i].second].push_back(edges[i].first);
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++ i) {
            if (ins[i] == 1) q.push(i);
        }
        
        while (!q.empty()) {
            int p = q.size();
            if (n <= 2) {
                for (int i = 0; i < n; ++ i) {
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }
            n -= p;
            while (p --) {
                int m = q.front();
                q.pop();
                ins[m] --;
                vector<int> v = tree[m];
                for (int i = 0; i < v.size(); ++ i) {
                    ins[v[i]] --;
                    if (ins[v[i]] == 1) q.push(v[i]);
                }
            }
        }
        
        return res;
    }
};