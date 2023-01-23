// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, unordered_map<int, int>> memo; 
        return recur(nums, S, 0, 0, memo);
    }
    
    int recur(vector<int>& nums, int S, int i, int sumSoFar, unordered_map<int, unordered_map<int, int>>& memo) {
        if(i == nums.size()) {
            return sumSoFar == S ? 1 : 0;
        }
        if(memo.find(i) != memo.end()) {
            if(memo[i].find(sumSoFar) != memo[i].end()) {
                return memo[i][sumSoFar];
            }
        }
        memo[i][sumSoFar] = recur(nums, S, i+1, sumSoFar+nums[i], memo) + recur(nums, S, i+1, sumSoFar-nums[i], memo);
        
        return memo[i][sumSoFar];
    }
};