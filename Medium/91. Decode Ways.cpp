// https://leetcode.com/problems/decode-ways/


class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(101, -1);
        return recur(s, s.length(), 0, dp);
    }
    
    int recur(string s, int n, int i, vector<int>& dp);
};

int
Solution::recur(string s, int n, int i, vector<int>& dp) {
    if(i >= n) {
        return 1;
    }
    
    if(s[i] == '0') {
        return 0;
    }
    
    if(dp[i] != -1) {
        return dp[i];
    }
    
    int one_digit = recur(s, n, i+1, dp);
    
    int two_digit = 0;
    if(i + 1 < n and (((s[i] - '0') * 10) + (s[i+1] - '0')) < 27) {
        two_digit = recur(s, n, i + 2, dp);
    }
    
    dp[i] = one_digit + two_digit;
    return dp[i];
    
}