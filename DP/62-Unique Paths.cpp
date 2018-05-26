class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++ i) {
            vector<int> v(m, 1);
            grid.push_back(v);
        }
        for (int i = 1; i < m; ++ i) {
            for (int j = 1; j < n; ++ j) {
                grid[j][i] = grid[j - 1][i] + grid[j][i - 1];
            }
        }
        return grid[n - 1][m - 1];
    }
};