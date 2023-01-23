// https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector(n, -1));
        
        return recur(triangle, n, 0, 0, dp);
    }
    
    int recur(vector<vector<int>>& triangle, int n, int r, int c,  vector<vector<int>>& dp) {
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        if(r == n - 1) {
            return triangle[r][c];
        }
        
        int left = recur(triangle, n, r+1, c, dp);
        int right = recur(triangle, n, r+1, c+1, dp);
        
        dp[r][c] = min(triangle[r][c] + left, triangle[r][c] + right);
        return dp[r][c];
    }
};