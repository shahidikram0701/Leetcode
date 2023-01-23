// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        
        int maxi = INT_MIN;
        
        int l_sum = 0;
        int r_sum = 0;
        while(l < n and r >= 0) {
            if(l_sum == 0) {
                l_sum = nums[l];
            } else {
                l_sum *= nums[l];
            }
            if(r_sum == 0) {
                r_sum = nums[r];
            } else {
                r_sum *= nums[r];
            }
            
            maxi = max(maxi, max(l_sum, r_sum));
            
            ++l;
            --r;
        }
        
        return maxi;
    }
};