// https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int dp[700][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> s;
        
        for(string str: strs) {
            int ones = 0;
            int zeros = 0;
            for(char c: str) {
                switch(c) {
                    case '0':
                        ++zeros;
                        break;
                    case '1':
                        ++ones;
                        break; 
                }
            }
            s.emplace_back(make_pair(zeros, ones));
        }
        
        for(int i = 0; i <= s.size(); ++i) {
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= n; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return recur(s, 0, m, n);
        
        
    }
    
    int recur(vector<pair<int, int>>& s, int i, int m, int n) {
        if(i >= s.size()) {
            return 0;
        }
        if(dp[i][m][n] != -1) {
            return dp[i][m][n];
        }
        int new_m = m - s[i].first;
        int new_n = n - s[i].second;
        pair<int, int> p = make_pair(m, n);
        if(new_m >= 0 and new_n >= 0) {
            dp[i][m][n] = max(1 + recur(s, i+1, new_m, new_n), recur(s, i+1, m, n));
        } else {
            dp[i][m][n] = recur(s, i+1, m, n);        
        }
        
        return dp[i][m][n];
    }
};