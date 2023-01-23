// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        
        int l = 0;
        int sum = 0;
        for(int r = 0; r < n; ++r) {
            sum += nums[r];
            if(sum < target) {
                continue;
            }
            if((r - l + 1) < mini) {
                mini = (r - l + 1);
            }
            
            while(l < r and sum >= target) {
                sum -= nums[l];
                ++l;
                if(sum >= target and (r - l + 1) < mini) {
                    mini = r - l + 1;
                }
            }
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};