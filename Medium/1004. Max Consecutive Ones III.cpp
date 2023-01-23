// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(k >= nums.size()) {
            return n;
        }

        int i = 0;
        int j = 0;
        int k_ = 0;

        int maxi = 0;

        while(i < n and j < n) {
            if(nums[j] == 0 and k_ < k) {
                while(j < n and nums[j] == 0 and k_ < k)  {
                ++k_;
                ++j;
                } 
            } else if(nums[j] == 0 and k_ >= k) {
                while(i < n and nums[i] == 1) {
                    ++i;
                }
                k_--;
                i++;
                continue;
                
            }
            while(j < n and nums[j] == 1)
                ++j;

            if(i <= j) {
                if(j - i > maxi) {
                    maxi = j - i;
                } 
            }
        }

        return maxi;



    }
};