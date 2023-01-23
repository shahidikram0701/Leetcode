// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return recur(nums, 0, memo);
    }
    
    int recur(vector<int>& nums, int i, vector<int>& memo) {
        if(i >= nums.size()) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        } 
        memo[i] = max(nums[i] + recur(nums, i + 2, memo), recur(nums, i + 1, memo));
        return memo[i];
    }  
};