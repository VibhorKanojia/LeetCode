class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m+2][n+2];
        
        for (int i = 0; i < m+2 ; i++){
            for (int j = 0; j < n+2 ; j++){
                dp[i][j] = 0;
            }
        }
        if (!obstacleGrid[0][0]) dp[1][1] = 1;
    
        for (int i = 1; i < m+1; i++){
            for (int j = 1; j < n+1; j++){
                if (obstacleGrid[i-1][j-1]) continue;
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m][n];
        
    }
};
