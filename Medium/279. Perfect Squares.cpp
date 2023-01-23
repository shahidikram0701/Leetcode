// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i * i <= n; ++i) {
            squares.push_back(i*i);
        }
        vector<int> dp(10001, -1);
        return recur(n, squares, dp);
        
        
    }

    int recur(int n, vector<int>& squares, vector<int>& dp) {
        if(n == 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        for(int j = 0; j < squares.size(); ++j) {
            if(squares[j] <= n) {
                ans = min(ans, 1 + recur(n - squares[j], squares, dp));
            }
        }

        dp[n] = ans;

        return dp[n];
    }
};