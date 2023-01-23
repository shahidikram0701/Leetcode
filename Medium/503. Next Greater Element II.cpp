// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        
        auto max_element_iterator = max_element(nums.begin(), nums.end());
        
        int maxi = *max_element_iterator;
        int maxi_i = max_element_iterator - nums.begin();
        vector<int> ans_i(n, maxi_i);
        int i = decrement(maxi_i, n);
        vector<int> ans(n, -1);
        
        while(i != maxi_i) {
            if(nums[i] != maxi) {
                int next_i = (i+1) % n;
                while(nums[next_i] <= nums[i]) {
                    next_i = ans_i[next_i];
                }
                ans_i[i] = next_i; 
            }
            i = decrement(i, n);
        }
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] != maxi)
                ans[i] = nums[ans_i[i]];
        }
        
        return ans;
        
    }
    
    int decrement(int i, int n) {
        int j = (i - 1) % n;
        if(j < 0) {
            j = n - 1;
        }
        return j;
    }
};