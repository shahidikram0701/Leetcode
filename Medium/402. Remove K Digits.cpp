// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int n = num.length();
        
        for(char digit: num) {
            if(s.empty()) {
                s.push(digit);
            } else {
                while(k > 0 and !s.empty() and s.top() > digit) {
                    s.pop();
                    --k;
                }
                s.push(digit);
            }
        }
        
        while(k > 0 and !s.empty()) {
            s.pop();
            --k;
        }
        
        string minNum = "";
        
        while(!s.empty()) {
            minNum += s.top();
            s.pop();
        }
        
        reverse(minNum.begin(), minNum.end());
        int i = 0;
        while(i < minNum.length() and minNum[i] == '0') {
            ++i;
        }
        if(i == minNum.length()) {
            return "0";
        }
        return minNum.substr(i);
    }
};