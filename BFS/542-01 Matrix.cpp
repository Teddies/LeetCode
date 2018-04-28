class Solution {
public:
    vector<vector<int>> res;
    
    void findAdjOnes(int n, int m, vector<vector<int>>& matrix) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (matrix[i][j] == 1) {
                    if (i - 1 >= 0 && matrix[i - 1][j] == 0) res[i][j] = 1;
                    if (i + 1 < n && matrix[i + 1][j] == 0) res[i][j] = 1;
                    if (j - 1 >= 0 && matrix[i][j - 1] == 0) res[i][j] = 1;
                    if (j + 1 < m && matrix[i][j + 1] == 0) res[i][j] = 1;
                } 
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return res;
        int n = matrix.size(), m = matrix[0].size();
        res = matrix;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                res[i][j] = 0;
            }
        }
        findAdjOnes(n, m, matrix);
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (res[i][j] == 1) {
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    q.push(p);
                }
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++ k) {
                int i = q.front().first;
                int j = q.front().second;
                if (i - 1 >= 0 && matrix[i - 1][j] == 1) {
                    int origin = res[i - 1][j];
                    res[i - 1][j] = res[i - 1][j] == 0 ? res[i][j] + 1 : min(res[i][j] + 1, res[i - 1][j]);
                    if (res[i - 1][j] != origin) {
                        pair<int, int> p;
                        p.first = i - 1;
                        p.second = j;
                        q.push(p);
                    }
                }
                if (i + 1 < n && matrix[i + 1][j] == 1) {
                    int origin = res[i + 1][j];
                    res[i + 1][j] = res[i + 1][j] == 0 ? res[i][j] + 1 : min(res[i][j] + 1, res[i + 1][j]);
                    if (res[i + 1][j] != origin) {
                        pair<int, int> p;
                        p.first = i + 1;
                        p.second = j;
                        q.push(p);
                    }
                }
                if (j - 1 >= 0 && matrix[i][j - 1] == 1) {
                    int origin = res[i][j - 1];
                    res[i][j - 1] = res[i][j - 1] == 0 ? res[i][j] + 1 : min(res[i][j] + 1, res[i][j - 1]);
                    if (res[i][j - 1] != origin) {
                        pair<int, int> p;
                        p.first = i;
                        p.second = j - 1;
                        q.push(p);
                    }
                }
                if (j + 1 < m && matrix[i][j + 1] == 1) {
                    int origin = res[i][j + 1];
                    res[i][j + 1] = res[i][j + 1] == 0 ? res[i][j] + 1 : min(res[i][j] + 1, res[i][j + 1]);
                    if (res[i][j + 1] != origin) {
                        pair<int, int> p;
                        p.first = i;
                        p.second = j + 1;
                        q.push(p);
                    }
                }
                q.pop();
            }
        }
        return res;
    }
};