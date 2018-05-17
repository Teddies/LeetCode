// Similar with problem 210
class Solution {
public:
    
    // Judge cycles in directed graph 
    // Return the path of the graph
    // Fix pattern:
    unordered_map<char, string> graph;
    unordered_map<char, int> visited, visiting;
    string res;
    
    bool DFS(char c) {
        if (visited[c] == 1) return true;
        // If it is leaf node
        if (graph.find(c) == graph.end()) {
            visited[c] = 1;
            // Put the leaf node first into the result
            // Eventually reverse this result
            res.push_back(c);
            return true;
        }
        if (visiting[c] == 1) return false;
        visiting[c] = 1;
        string s = graph[c];
        for (int i = 0; i < s.size(); ++ i) {
            if (DFS(s[i]) == false) return false;
        }

        // After all the children are checked and there
        // is no cycles, update the visited flag, change
        // the visiting flag and put this letter into the result
        visiting[c] = 0;
        visited[c] = 1;
        res.push_back(c);
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        // First check which letters has been appeared
        vector<int> appear(26, 0);
        for (int i = 0; i <words.size(); ++ i) {
            for (int j = 0; j < words[i].size(); ++ j) {
                char c = words[i][j];
                appear[c - 'a'] = 1;
            }
        }
        
        for (int i = 1; i < words.size(); ++ i) {
            string str1 = words[i - 1];
            string str2 = words[i];
            int size = min(str1.size(), str2.size());
            for (int j = 0; j < size; ++ j) {
                if (str1[j] != str2[j]) {
                    graph[str1[j]].push_back(str2[j]);
                    appear[str1[j] - 'a'] = 0;
                    appear[str2[j] - 'a'] = 0;
                    break; 
                }
            }
        }
        
        unordered_map<char, string>::iterator it = graph.begin();
        while (it != graph.end()) {
            if (DFS(it->first) == false) return "";
            it ++;
        }
        // At last reverse the result path
        reverse(res.begin(), res.end());

        // The letter with appear[i] == 1 means that we 
        // don't know the lexical order of these letters
        // So we directly add these letter at last
        for (int i = 0; i < 26; ++ i) {
            if (appear[i] == 1) res.push_back(i + 'a');
        }

        return res;
    }
};