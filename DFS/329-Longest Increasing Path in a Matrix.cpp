// Simple DFS
// Trick here is to use a mark matrix to record the result of the visited nodes
// Thus these nodes will not be DFS again later and will directly return the result
// The mark matrix is kind of like a cache to speed up the performance
class Solution {
public:
    int DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& mark) {
        int n1 = 1, n2 = 1, n3 = 1, n4 = 1;
        if (mark[i][j] != -1) return mark[i][j];
        if (i - 1 >= 0 && matrix[i - 1][j] < matrix[i][j]) {
            n1 += DFS(matrix, i - 1, j, mark);
        }
        if (i + 1 < matrix.size() && matrix[i + 1][j] < matrix[i][j]) {
            n2 += DFS(matrix, i + 1, j, mark);
        }
        if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j]) {
            n3 += DFS(matrix, i, j - 1, mark);
        }
        if (j + 1 < matrix[i].size() && matrix[i][j + 1] < matrix[i][j]) {
            n4 += DFS(matrix, i, j + 1, mark);
        }
        mark[i][j] = max(max(n1, n2), max(n3, n4));
        return max(max(n1, n2), max(n3, n4));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max = 0;
        vector<vector<int>> mark = matrix;
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                mark[i][j] = -1;
            }
        }
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                if (mark[i][j] != -1)
                    continue;
                int n = DFS(matrix, i, j, mark);
                max = n > max ? n : max;
            }
        }
        return max;
    }
};