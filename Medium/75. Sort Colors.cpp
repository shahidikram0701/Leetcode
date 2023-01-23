// https://leetcode.com/problems/sort-colors/

class Solution {
public:
   void sortColors(vector<int>& nums) {
   int start=0, index = 0, end = nums.size()-1;
   while(index<=end && start<=end){
       if(nums[index] == 0){
           nums[index] = nums[start];
           nums[start] = 0;
           start++;
           index++;
       }
       else if(nums[index] == 2){
           nums[index] = nums[end];
           nums[end] = 2;
           end--;
       }
       else{
           index++;
           }
       }
   }
};