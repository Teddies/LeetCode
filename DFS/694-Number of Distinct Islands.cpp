class Solution {
public:   
    void DFS(int i, int j, vector<vector<int>>& grid, string& trace, int id) {
        grid[i][j] = 0;
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            trace.push_back('u');
            trace.push_back(id + '0');
            DFS(i - 1, j, grid, trace, id + 1);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            trace.push_back('d');
            trace.push_back(id + '0');
            DFS(i + 1, j, grid, trace, id + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            trace.push_back('l');
            trace.push_back(id + '0');
            DFS(i, j - 1, grid, trace, id + 1);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
            trace.push_back('r');
            trace.push_back(id + '0');
            DFS(i, j + 1, grid, trace, id + 1);
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        unordered_map<string, int> traceMap;
        int res = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] == 1) {
                    string trace = "";
                    DFS(i, j, grid, trace, 0);
                    if (traceMap.find(trace) == traceMap.end()) {
                        res ++;
                        traceMap[trace] = 1;
                    }
                }
            }
        }
        return res;
    }
};