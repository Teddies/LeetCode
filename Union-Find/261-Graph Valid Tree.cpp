// Time complexity: O(vertex * edges)
// Space complexity: O(n)

// Notice this method is not adapted if the input contains 
// duplicate items, like input [[0,1],[1,0],[1,2],[2,3],[2,3]]
// In this situation, DFS is a better algorithm
// Or we can first remove the duplicates by constructing a hash map (similar with what DFS does)
class Solution {
public:
	// This function uses to find the final destination that has
	// never been visited, and compare whether the final destination
	// of a visited node is equal to the current node.
	// For example, [0,1],[1,2],[2,3],[1,3]
	// For 0, 1, 2, the final destination are all 3, since
	// 0 - 1 - 2 - 3
	// But when 3 is the first time visited, the destination is also 3
	// Thus it should not be connected with other previous node which 
	// will generates a ring

    int find(vector<int>& roots, int node) {
        while (roots[node] != -1) {
            node = roots[node];
        } 
        return node;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 1 && edges.size() == 0) return true;
        if (n < 1 || edges.empty() || edges.size() != n - 1) return false;
        vector<int> roots(n, -1);
        for (int i = 0; i <edges.size(); ++ i) {
            int n1 = find(roots, edges[i].first);
            int n2 = find(roots, edges[i].second);
            if (n1 == n2) return false;
            // Only this line changes the union-find cotent
            roots[n1] = n2;
        }
        return true;
    }
};
