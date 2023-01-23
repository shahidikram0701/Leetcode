// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<unordered_map<int, int>> dp(n + 1, unordered_map<int, int>{});
        return recur(1, n, k, target, dp);
    }

    int recur(int i, int n, int k, int target, vector<unordered_map<int, int>>& dp) {
        if(i > n) {
            return target == 0 ? 1 : 0;
        }

        if(target < 0) {
            return 0;
        }

        if(dp[i].find(target) != dp[i].end()) {
            return dp[i][target];
        }

        long ans = 0;
        for(int j = 1; j <= k; ++j) {
            ans += (recur(i + 1, n, k, target - j, dp) % 1000000007);
        }

        dp[i][target] = ans % 1000000007;

        return dp[i][target];

    }
};