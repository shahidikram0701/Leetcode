// https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        unordered_map<int, bool> digits{ {0, false}, {1, false}, {2, false}, {3, false}, {4, false}, {5, false}, {6, false}, {7, false}, {8, false}, {9, false} };
        int ans = 1;
        for(int j = 1; j <= n; ++j) {
            for(int i = 1; i <= 9; ++i) {
                digits[i] = true;
                ans += recur(j, 1, digits);
                digits[i] = false;
            }
        }
       
        return ans;
    }
    
    int recur(int n, int i, unordered_map<int, bool>& digits) {
        if(i >= n) {
            return 1;
        }
        int ans = 0;
        for(int j = 0; j < 10; ++j) {
            if(!digits[j]) {
                digits[j] = true;
                ans += recur(n, i+1, digits);
                digits[j] = false;
            }
        }
        return ans;
    }
};

// Approach 2

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        
        int subans = 9;
        for(int i = 1; i <= n; ++i) {
            ans += subans;
            subans *= (9 - i + 1);
        }
        
        return ans;
        
    }
};