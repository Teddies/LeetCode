// Treat the graph as a tree with repeatitive nodes
// Conduct the post-order traversal to this tree
// Reverse the traversal result
class Solution {
public:
	// Keep updating the res vector
	// Actually is the post-order traversal of the tree
    void DFS(string start, vector<string>& res) {
        if (hash[start].empty()) {
            res.push_back(start);
            return;
        }
        while (!hash[start].empty()) {
            string s = hash[start].front();
            // Break the visited edge to avoid forever loop
            hash[start].pop_front();
            DFS(s, res);
        }
        // As this is a post-order tree traversal
        // so we add the root node at the very last
        res.push_back(start);
        return;
    }
    
    vector<string> reverse(vector<string> v) {
        vector<string> res;
        for (int i = v.size() - 1; i >= 0; -- i) {
            res.push_back(v[i]);
        }
        return res;
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if (tickets.empty()) return res;
        for (int i = 0; i < tickets.size(); ++ i) {
            hash[tickets[i].first].push_back(tickets[i].second);
        }
        // Use deque to increase the speed of delete or insert nodes
        unordered_map<string, deque<string>>::iterator it;
		// Sort the nodes with the lexical order
        for (it = hash.begin(); it != hash.end(); it ++) {
            sort((it->second).begin(), (it->second).end());
        }
        string start = "JFK";
        DFS(start, res);
        // The result is the reverse order of the res vector
        return reverse(res);
    }
    
private:
    unordered_map<string, deque<string>> hash;
};
