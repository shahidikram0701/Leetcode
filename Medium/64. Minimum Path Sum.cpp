// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return recur(grid, 0, 0, dp);
    }

    int recur(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size()) {
            return INT_MAX;
        }

        if(i == grid.size() - 1 and j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = grid[i][j] + min(recur(grid, i + 1, j, dp), recur(grid, i, j + 1, dp));
        return dp[i][j];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        int sum = 0;
        for(int i = 0; i < r; ++i) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for(int i = 0; i < c; ++i) {
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        
        for(int i = 1; i < r; ++i) {
            for(int j = 1; j < c; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] += grid[i][j];
            }
        }
        
        return dp[r-1][c-1];
    }
};