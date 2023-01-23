// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> dp(nums.size(), -1);
        for(int i = 0; i < nums.size(); ++i) {
            maxi = max(maxi, recur(nums, i, dp));
        }
         return maxi;
    }
    
    int recur(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        } 
        
        int maxi = 1;
        for(int j = i + 1; j < nums.size(); ++j) {
            if(nums[j] > nums[i]) {
                maxi = max(maxi, 1 + recur(nums, j, dp));   
            }
            
        }
        
        dp[i] = maxi;
        return dp[i];
        
    }
};


// Solution 2

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        
        return recur(nums, 0, dp, -1);
    }
    
    int recur(vector<int>& nums, int i, vector<vector<int>>& dp, int prev_) {
        int prev = prev_ + 1;

        if (i >= nums.size()) {
            return 0;
        }
        
        if(dp[i][prev] != -1) {
            return dp[i][prev];
        } 
        
        int including = 0;
        int excluding = 0;
        if(prev_ == -1 or nums[i] > nums[prev_]) {
            including = 1 + recur(nums, i + 1, dp, i);
        }
        excluding = recur(nums, i + 1, dp, prev_);
        
        dp[i][prev] = max(including, excluding);
        return dp[i][prev];
        
    }
};

// Solution 3 - Binary Search

/**
Solution 2: Greedy with Binary Search

Let's construct the idea from following example.
Consider the example nums = [2, 6, 8, 3, 4, 5, 1], let's try to build the increasing subsequences starting with an empty one: sub1 = [].
Let pick the first element, sub1 = [2].
6 is greater than previous number, sub1 = [2, 6]
8 is greater than previous number, sub1 = [2, 6, 8]
3 is less than previous number, we can't extend the subsequence sub1, but we must keep 3 because in the future there may have the longest subsequence start with [2, 3], sub1 = [2, 6, 8], sub2 = [2, 3].
With 4, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4].
With 5, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5].
With 1, we can't extend neighter sub1 nor sub2, but we need to keep 1, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5], sub3 = [1].
Finally, length of longest increase subsequence = len(sub2) = 4.

In the above steps, we need to keep different sub arrays (sub1, sub2..., subk) which causes poor performance. But we notice that we can just keep one sub array, when new number x is not greater than the last element of the subsequence sub, we do binary search to find the smallest element >= x in sub, and replace with number x.
Let's run that example nums = [2, 6, 8, 3, 4, 5, 1] again:
Let pick the first element, sub = [2].
6 is greater than previous number, sub = [2, 6]
8 is greater than previous number, sub = [2, 6, 8]
3 is less than previous number, so we can't extend the subsequence sub. We need to find the smallest number >= 3 in sub, it's 6. Then we overwrite it, now sub = [2, 3, 8].
4 is less than previous number, so we can't extend the subsequence sub. We overwrite 8 by 4, so sub = [2, 3, 4].
5 is greater than previous number, sub = [2, 3, 4, 5].
1 is less than previous number, so we can't extend the subsequence sub. We overwrite 2 by 1, so sub = [1, 3, 4, 5].
Finally, length of longest increase subsequence = len(sub) = 4.
 * /