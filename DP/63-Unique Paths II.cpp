class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        else obstacleGrid[0][0] = 1;
        // Notice here on the first row or the first column, if there is 
        // an onstacle, then the ways towards the later points after the 
        // obstacle is also 0.
        int val = 0;
        for (int i = 1; i < obstacleGrid.size(); ++ i) {
            if (val == 1) obstacleGrid[i][0] = 0;
            else if (obstacleGrid[i][0] == 1) {
                obstacleGrid[i][0] = 0;
                val = 1;
            }
            else obstacleGrid[i][0] = 1;
        }
        val = 0;
        for (int i = 1; i < obstacleGrid[0].size(); ++ i) {
            if (val == 1) obstacleGrid[0][i] = 0;
            else if (obstacleGrid[0][i] == 1) {
                obstacleGrid[0][i] = 0;
                val = 1;
            }
            else obstacleGrid[0][i] = 1;
        }

        for (int i = 1; i < obstacleGrid.size(); ++ i) {
            for (int j = 1; j < obstacleGrid[i].size(); ++ j) {
                obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};