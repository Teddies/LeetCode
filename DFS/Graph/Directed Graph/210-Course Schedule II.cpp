// Topological Sorting + DFS
// Visited and visiting two status for every nodes
// Visited is used to reduce the DFS branches
// Visiting is used for check cycles
// Could also be used for problem 207
class Solution {
public:
    vector<int> res;
    
    bool DFS(int n, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& visiting, unordered_map<int, int>& visited) {
        if (visited[n] == 1) return true;
        if (graph.find(n) == graph.end()) {
            visited[n] = 1;
            res.push_back(n);
            return true;
        }
        if (visiting[n] == 1) return false;
        visiting[n] = 1;
        vector<int> v = graph[n];
        for (int i = 0; i < v.size(); ++ i) {
            bool b = DFS(v[i], graph, visiting, visited);
            if (b == false) return false;
        }
        visiting[n] = 0;
        visited[n] = 1;
        res.push_back(n);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> visiting, visited;
        for (int i = 0; i < prerequisites.size(); ++ i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for (int i = 0; i < numCourses; ++ i){
            if (visited.find(i) == visited.end()) {
                bool b = DFS(i, graph, visiting, visited);
                if (b == false) {
                    res.clear();
                    return res;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};