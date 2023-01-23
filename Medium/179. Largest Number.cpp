// https://leetcode.com/problems/largest-number/

#include<string>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int op1, int op2) {
            string a = to_string(op1);
            string b = to_string(op2);
            
            return a+b > b+a;    
        });
        string ans = "";
        for(int i: nums) {
            ans += to_string(i);
        }
        if(ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};