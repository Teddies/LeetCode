class Solution {
public:
    bool DFS(int i, int j, vector<vector<char>>& picture) {
        int n = picture.size(), m = picture[0].size();
        bool res = true;
        picture[i][j] = 'W';
        int si = i, sj = j;
        for (int k = 0; k < n; ++ k) {
            if (picture[k][j] == 'B') {
                res = false;
                DFS(k, j, picture);
            }
        }
        for (int k = 0; k < m; ++ k) {
            if (picture[i][k] == 'B') {
                res = false;
                DFS(i, k, picture);
            }
        }
        return res;
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty()) return 0;
        int n = picture.size(), m = picture[0].size();
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (picture[i][j] == 'B') {
                    if (DFS(i, j, picture)) res ++;
                }
            }
        }
        return res;
    }
};