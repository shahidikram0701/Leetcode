// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<unordered_map<int, int>> dp(201, unordered_map<int, int>{});
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) {
            return false;
        }
        return recur(nums, 0, sum / 2, dp);
    }


    bool recur(vector<int>& nums, int i, long long s, vector<unordered_map<int, int>>& dp) {
        if(i >= nums.size()) {
            return s == 0;
        }

        if(dp[i].find(s) != dp[i].end()) {
            return dp[i][s];
        }
        dp[i][s] = (recur(nums, i + 1, s - nums[i], dp) or recur(nums, i + 1, s, dp));

        return dp[i][s];
        
    }
};