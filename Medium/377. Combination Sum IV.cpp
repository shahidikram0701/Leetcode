// https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001, -1);
        return recur(nums, target, dp);
    }
    
    int recur(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) {
            dp[target] = 1;
            return 1;
        }
        if(target < 0) {
            return 0;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ans += recur(nums, target - nums[i], dp);
        }
        
        dp[target] = ans;
        
        return dp[target];
    }
};