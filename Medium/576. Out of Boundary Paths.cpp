// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return recur(m, n, maxMove, startRow, startColumn, dp);
    }

    int recur(int m, int n, int move, int i, int j, vector<vector<vector<int>>>& dp) {
        if(i < 0 or i >= m or j < 0 or j >= n) {
            return 1;
        }
        if(move <= 0) {
            return 0;
        }

        if(dp[i][j][move] != -1) {
            return dp[i][j][move];
        }
        int mod = 1000000007;
        dp[i][j][move] =  
                (((recur(m, n, move - 1, i - 1, j, dp) % mod + 
                recur(m, n, move - 1, i + 1, j, dp) % mod) % mod + 
                recur(m, n, move - 1, i, j - 1, dp) % mod) % mod +
                recur(m, n, move - 1, i, j + 1, dp) % mod) % mod;

        return dp[i][j][move] % mod;
        
    }
};