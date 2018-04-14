// Note this problem could be also easily solved with union-find method
// Time complexity: O(vertex * edges)
// Space complexity: O(n)
class Solution {
public:
    bool DFS(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& visited, int node, int parent) {
        visited[node] = 1;
        vector<int> list = graph[node];
        for (int i = 0; i < list.size(); ++ i) {
            if (list[i] == parent) continue;
            if (visited.find(list[i]) != visited.end()) return false;
            bool res = DFS(graph, visited, list[i], node);
            if (res == false) return false;
        }
        return true;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
    	// Basic cases
        if (n == 1 && edges.empty()) return true;
        if (n < 1 || edges.empty() || edges.size() != n - 1) return false;

        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> visited;
        bool res;

        // First, transfer the graph into another form 
        for (int i = 0; i < edges.size(); ++ i) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }

        // Then begin DFS
        visited[0] = 1;
        for (int i = 0; i < graph[0].size(); ++ i) {
            res = DFS(graph, visited, graph[0][i], 0);
            if (res == false) return false;
        }
        
        // Notice the final step
        // Used for checking whether there is multiple pieces in the graph
        return visited.size() == n ? true : false;
    }
};

