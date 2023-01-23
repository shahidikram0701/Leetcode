// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        sort(coins.rbegin(), coins.rend());
        vector<vector<int>> dp(12, vector<int>(10001, -1));
        int ans = recur(coins, 0, amount, dp);
        return  ans == INT_MAX ? -1: ans;
    }


    int recur(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if(i >= coins.size()) {
            return amount > 0 ? INT_MAX : 0;
        }

        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int including = INT_MAX;
        int excluding = INT_MAX;
        if(coins[i] <= amount) {
            including = recur(coins, i, amount - coins[i], dp);
            if(including != INT_MAX) {
                including++;
            }
        }

        excluding = recur(coins, i + 1, amount, dp);


        dp[i][amount] = min(including, excluding);

        return dp[i][amount];
    }
};