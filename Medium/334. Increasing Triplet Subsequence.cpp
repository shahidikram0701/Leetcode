// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for(int num: nums){
            if(num <= n1){
                // minimum number seen so far
                n1 = num;
            }
            // Add = to avoid entering else case
            else if(num <= n2){
                // minimum number with a SMALLER number to the left seen so far
                n2 = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};