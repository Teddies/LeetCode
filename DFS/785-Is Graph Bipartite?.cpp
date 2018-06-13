class Solution {
public:
    bool DFS(int n, int val, vector<int>& partition, vector<vector<int>>& graph) {
        partition[n] = val;
        vector<int> v = graph[n];
        for (int i = 0; i < v.size(); ++ i) {
            if (partition[v[i]] == -1) {
                if (DFS(v[i], 1 - val, partition, graph) == false) return false;
            }
            else {
                if (partition[v[i]] != 1 - val) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> partition(graph.size(), -1);
        for (int i = 0; i < graph.size(); ++ i) {
            if (partition[i] == -1) {
                if (DFS(i, 1, partition, graph) == false) return false;
            }
        }
        return true;
    }
};