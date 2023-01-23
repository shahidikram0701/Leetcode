// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return recur(obstacleGrid, m, n, 0, 0, dp);
    }
    
    int recur(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i >= m or j >= n) {
            return 0;
        }
        if(obstacleGrid[i][j] == 1) {
            return 0;
        }
        
        if(i == m - 1 and j == n - 1) {
            return 1;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        return dp[i][j] = recur(obstacleGrid, m, n, i + 1, j, dp) + recur(obstacleGrid, m, n, i, j + 1, dp);
    }
};