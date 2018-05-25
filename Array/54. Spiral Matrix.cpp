class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int row = matrix.size();
        int column = matrix[0].size();
        if (column == 0) return res;
        
        vector<pair<int, int>> direction;
        direction.push_back(pair<int, int>(0, 1));
        direction.push_back(pair<int, int>(1, 0));
        direction.push_back(pair<int, int>(0, -1));
        direction.push_back(pair<int, int>(-1, 0));
        
        vector<vector<int>> visited = matrix;
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j){
                visited[i][j] = 0;
            }
        }
        
        int dir = 0;
        int i = 0, j = -1;
        while (res.size() < row * column) { 
            int ci = direction[dir % 4].first;
            int cj = direction[dir % 4].second;
            // Change the elements to be the next element
            // in case the same element is traversed twice
            i += ci;
            j += cj;
            while (i >= 0 && i < row && j >= 0 && j < column && visited[i][j] == 0) {
                res.push_back(matrix[i][j]);
                visited[i][j] = 1;
                i += ci;
                j += cj;
            }
            i -= ci;
            j -= cj;
            dir ++;
        }
        return res;
    }
};