// https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pprev = INT_MIN;
        int prev = nums[0];
        bool flag = true;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] >= prev) {
                pprev = prev;
                prev = nums[i];
                continue;
            }
            else {
                if(nums[i] >= pprev) {       
                    if(flag) {
                        flag = false;
                        prev = nums[i];
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if(flag) {
                        flag = false;
                    }
                    else {
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
};