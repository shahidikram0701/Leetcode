// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return recur(nums, 0, false, dp);
    }
    
    int recur(vector<int>& nums, int i, bool firstRobbed, vector<vector<int>>& dp) {
        if(i >= nums.size()) {
            return 0;
        }
        if(dp[i][firstRobbed] != -1) {
            return dp[i][firstRobbed];
        }
        if(i == nums.size() - 1 and firstRobbed) {
            return 0;
        }
        int rob = nums[i] + recur(nums, i+2, i == 0 or firstRobbed, dp);
        int dontRob = recur(nums, i+1, firstRobbed, dp);
        
        dp[i][firstRobbed] = max(rob, dontRob);
        
        return dp[i][firstRobbed];
    }
    
};