// Could be further improved with better algorithms
// This algorithm runs 39ms, which performs not well enough

class Solution {
public:
	// Use to record which nodes has been visited
	// Because the graph could be composed with multiple parts
	// Like 1 - 2 - 3   5 - 6
	//       \ /         \ /
	//        4           7
	// The graph above is composed with two parts and could be valid
	// And we only need to execute DFS once for any node in each part
	// In the above part, we only need to execute DFS(1) and DFS(5) 

	// "visited" hash map is different, it checks whether there are rings
	// Since this is a directed graph, we need to change the visited points
	// back to unvisited when we return the stack
	// For example, 0 -> 1 -> 2 -> 3  (3 points to 4)
	//                   |         |
	//                    -------> 4
	// In this graph, it is valid since there is no ring
	// But 1 will be visited twice: 0 -> 1 -> 2 -> 3 -> 4, and
	//                              0 -> 1 -> 4
	// So we need to change the 1 into unvisited after each time calling DFS 

    unordered_map<int, int> partial;
    bool DFS(int n, unordered_map<int, vector<int>>& hash, unordered_map<int, int>& visited) {
        if (hash.find(n) == hash.end()) return true;
        // Mark this point as visited
        visited[n] = 1;
        partial[n] = 1;
        vector<int> v = hash[n];
        for (int i = 0; i < v.size(); ++ i) {
            if (visited[v[i]]) return false;
            bool res = DFS(v[i], hash, visited);
            if (res == false) return false;
        }
        // Change back this point into unvisited
        // since this is a directed graph
        visited[n] = 0;
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        unordered_map<int, vector<int>> hash;
        unordered_map<int, int> visited;
        for (int i = 0; i < prerequisites.size(); ++ i) {
            hash[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        unordered_map<int, vector<int>>::iterator it;
        for (it = hash.begin(); it != hash.end(); it ++) {
        	// If found, means this part of graph has already been checked
            if (partial[it->first]) continue;
            bool res = DFS(it->first, hash, visited);
            if (res == false) return false;
        }
        return true;
    }
};