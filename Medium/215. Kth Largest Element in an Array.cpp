// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { 
        int n = nums.size();
        return recur(nums, n - k, 0, n-1);
    }
    
    int recur(vector<int>& nums, int k, int _l, int _r) {
        int l = _l;
        int r = _r;
        int pivot = nums[_l];
        while(l < r) {
            while(l < _r and nums[l] <= pivot) {
                ++l;
            }
            while(r > _l and nums[r] > pivot) {
                --r;
            }
            
            if(l < r) {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }
        }
        if(r > _l) {
            int t = nums[_l];
            nums[_l] = nums[r];
            nums[r] = t;
            
        }
        if(r == k) {        
            return nums[r];
        }
        return k > r ? recur(nums, k, l, _r) : recur(nums, k, _l, r-1);
    }
};