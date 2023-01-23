// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
   int findMin(vector<int>& nums) {
       int l=0, r=nums.size()-1, mid;
       while(l<r){
           mid = l + (r-l)/2;
           // If mid is greater than r, something is weird
           // For example, [4, 5, 6, 7, 0, 1, 2] 7>2
           if(nums[mid]>nums[r]){
               l=mid+1;
           }
           else{
               // Not mid -1 to account for
               // [5,6,7,0, 1,2,3] -> 0 should be included in left half
               r=mid;
           }
       }
       return nums[l];
   }
       
};