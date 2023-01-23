// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        vector<vector<bool>> table(n, vector<bool>(n, 0));
        
        int count = 0;
        
        for(int i = 0; i < n; ++i) {
            table[i][i] = true;
            ++count;
        }
        
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                table[i][j] = (s[i] == s[j]);
                if ((i + 1) <= (j - 1)) {
                    table[i][j] = table[i][j] and (table[i+1][j-1]);
                }
                count += (table[i][j] ? 1 : 0);
            }
        }
        
        return count;

    }
};