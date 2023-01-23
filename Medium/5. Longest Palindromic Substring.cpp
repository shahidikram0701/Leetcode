class Solution {
public:
    string longestPalindrome(string s) {
        string longestPalindrome = "";
        
        for(int i = 0; i < s.length(); ++i) {
            string palindrome = getPalindromeSubstring(s, i);
            
            if(palindrome.length() > longestPalindrome.length()) {
                longestPalindrome = palindrome;
            }
        }
        
        return longestPalindrome;
    }
    
    string getPalindromeSubstring(string s, int i) {
        int n = s.length();
        
        string evenPalindrome = "";
        string oddPalindrome = "";
        
        int l = i;
        int r = i;
        
        while(l >= 0 and r < n and s[l] == s[r]) {
            --l;
            ++r;
        }
        
        oddPalindrome += s.substr(l+1, (r) - (l + 1));
        
        l = i;
        r = i + 1;
        
        while(l >= 0 and r < n and s[l] == s[r]) {
            --l;
            ++r;
        }
        
        evenPalindrome += s.substr(l+1, (r) - (l + 1));
        
        
        return oddPalindrome.length() > evenPalindrome.length() ? oddPalindrome : evenPalindrome;
        
    }
};