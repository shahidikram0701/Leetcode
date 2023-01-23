// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        unordered_map<string, bool> dp;
        vector<string> sub_ans = {};
        recur(s, n, -1, sub_ans, ans, dp);
        
        return ans;
    }
    
    void recur(string s, int n, int i, vector<string>& sub_ans, vector<vector<string>>& ans, unordered_map<string, bool>& dp) {
        if(i == n-1) {
            ans.emplace_back(sub_ans);
            return;
        }
        string str = "";
        for(int j = i + 1; j < n; ++j) {
            str += s[j];
            if(dp.find(str) == dp.end()) {
                dp[str] = isPalindrome(str);
            }
            bool stringIsPalindrome = dp[str];
            if(stringIsPalindrome) {
                sub_ans.emplace_back(str);
                recur(s, n, j, sub_ans, ans, dp);
                sub_ans.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};