// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // main idea is if a[i...] and b[j...] are same subarrays,
        // then a[i+1...] and b[j+1...] are same subarrays
        // if a[i] == b[j] then the max same subarray would be 1 + maxSubarray(a[i+1...], b[j+1...])
        int l1 = nums1.size();
        int l2 = nums2.size();
        int maxi = INT_MIN;
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        for(int i = 0; i < l1; ++i) {
            for(int j = 0; j < l2; ++j) {
                int local_maxi = recur(nums1, l1, nums2, l2, i, j, dp);
                if(local_maxi > maxi) {
                    maxi = local_maxi;
                }
            }
        }
        return maxi;
    }
    
    int recur(vector<int>& nums1, int l1, vector<int>& nums2, int l2, int i, int j, vector<vector<int>>& dp) {
        if(i >= l1 or j >= l2) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = 0;
        if(nums1[i] == nums2[j]) {
            dp[i][j] = 1 + recur(nums1, l1, nums2, l2, i+1, j+1, dp);;
        }
        
        return dp[i][j];
    }
};