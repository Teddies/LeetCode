class Solution {
public:
    void DFS(unordered_map<int, vector<int>>& graph, vector<int>& visited, int n) {
        int root = n;
        visited[n] = 0;
        vector<int> v = graph[root];
        for (int i = 0; i < v.size(); ++ i) {
            if (visited[v[i]] == 1) DFS(graph, visited, v[i]);
        }
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (edges.empty()) return n;
        unordered_map<int, vector<int>> graph;
        int m = edges.size();
        for (int i = 0; i < m; ++ i) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        int res = 0;
        vector<int> visited(n, 1);
        for (int i = 0; i < visited.size(); ++ i) {
            if (visited[i] == 1) {
                DFS(graph, visited, i);
                res ++;
            }
        }
        return res;        
    }
};