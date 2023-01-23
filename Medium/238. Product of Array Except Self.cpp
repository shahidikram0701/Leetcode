// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> soln(n, 1);
        int i;
        int acc = 1;
        for(i = 1; i < n; ++i) {
            acc *= nums[i-1];
            soln[i] *= acc;
        }
        acc = 1;
        for(i = n-2; i >= 0; --i) {
            acc *= nums[i+1];
            soln[i] *= acc;
        }
        
        return soln;
    }
};