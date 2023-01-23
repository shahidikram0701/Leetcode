// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        
        bool found = false;
        int ans;
        
        while(!found and l < r) {
            int m = l + ((r - l) / 2);
            
            if(m - 1 >= 0 and m + 1 < n and nums[m] > nums[m - 1] and nums[m] > nums[m + 1]) {
                found = true;
            }
            else if(m - 1 < 0 and m + 1 < n and nums[m] > nums[m + 1]) {
                found = true;
            }
            else if(m + 1 >= n and m - 1 >= 0 and nums[m] > nums[m - 1]) {
                found = true;
            }
            else if(m - 1 >= 0 and nums[m - 1] > nums[m]) {
                r = m - 1;
            }
            else if(m + 1 < n and nums[m + 1] > nums[m]) {
                l = m + 1;
            }
            
            if(found) {
                ans = m;
            }
        }
        return found ? ans : l;
    }
};