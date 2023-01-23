// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return recur(1, 1, m, n, dp);   
    }
    
    int recur(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if( i == m and j == n) {
            dp[i][j] = 1;
            return 1;
        }
        if( i > m || j > n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = recur(i, j+1, m, n, dp) + recur(i+1, j, m, n, dp);
        return dp[i][j];
    }
};