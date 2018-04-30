class Solution {
public:
    vector<vector<int>> pacific;
    vector<vector<int>> atlentic;
    
    void BFS(vector<vector<int>>& matrix, int flag) {
        int n = matrix.size(), m = matrix[0].size();
        queue<pair<int, int>> q;
        if (flag == 0) {
            // Pacific
            for (int i = 0; i < m; ++ i) {
                pair<int, int> v; v.first = 0; v.second = i;
                q.push(v);
            }
            for (int i = 0; i < n; ++ i) {
                pair<int, int> v; v.first = i; v.second = 0;
                q.push(v);
            }
            while (!q.empty()) {
                int i = q.front().first;
                int j = q.front().second;
                int val = matrix[i][j];
                pacific[i][j] = 1; 
                if (i - 1 >= 0 && val <= matrix[i - 1][j] && pacific[i - 1][j] == 0) {
                    pair<int, int> v; v.first = i - 1; v.second = j;
                    q.push(v);
                }
                if (i + 1 < n && val <= matrix[i + 1][j] && pacific[i + 1][j] == 0) {
                    pair<int, int> v; v.first = i + 1; v.second = j;
                    q.push(v);  
                }   
                if (j - 1 >= 0 && val <= matrix[i][j - 1] && pacific[i][j - 1] == 0) {
                    pair<int, int> v; v.first = i; v.second = j - 1;
                    q.push(v); 
                }
                if (j + 1 < m && val <= matrix[i][j + 1] && pacific[i][j + 1] == 0) {
                    pair<int, int> v; v.first = i; v.second = j + 1;
                    q.push(v);    
                }
                q.pop();
            }
        }
        else {
            // Atlentic
            for (int i = 0; i < m; ++ i) {
                pair<int, int> v; v.first = n - 1; v.second = i;
                q.push(v);
            }
            for (int i = 0; i < n; ++ i) {
                pair<int, int> v; v.first = i; v.second = m - 1;
                q.push(v);
            }
            while (!q.empty()) {
                int i = q.front().first;
                int j = q.front().second;
                int val = matrix[i][j];
                atlentic[i][j] = 1;
                if (i - 1 >= 0 && val <= matrix[i - 1][j] && atlentic[i - 1][j] == 0) {
                    pair<int, int> v; v.first = i - 1; v.second = j;
                    q.push(v);
                }
                if (i + 1 < n && val <= matrix[i + 1][j] && atlentic[i + 1][j] == 0) {
                    pair<int, int> v; v.first = i + 1; v.second = j;
                    q.push(v);  
                }   
                if (j - 1 >= 0 && val <= matrix[i][j - 1] && atlentic[i][j - 1] == 0) {
                    pair<int, int> v; v.first = i; v.second = j - 1;
                    q.push(v); 
                }
                if (j + 1 < m && val <= matrix[i][j + 1] && atlentic[i][j + 1] == 0) {
                    pair<int, int> v; v.first = i; v.second = j + 1;
                    q.push(v);    
                }
                q.pop();
            }
        }
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if (matrix.empty()) return res;
        int n = matrix.size(), m = matrix[0].size();
        pacific = matrix;
        atlentic = matrix;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                pacific[i][j] = 0;
                atlentic[i][j] = 0;
            }
        }
        BFS(matrix, 0);
        BFS(matrix, 1);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (pacific[i][j] == 1 && atlentic[i][j] == 1) {
                    pair<int, int> location;
                    location.first = i;
                    location.second = j;
                    res.push_back(location);
                }
            }
        }
        return res;
    }
};