// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openBrackets;
        stack<int> starWars;
        
        for(int i = 0; i < s.length(); ++i) {
            char c = s[i];
            switch(c) {
                case '(':
                    openBrackets.push(i);
                    break;
                case '*':
                    starWars.push(i);
                    break;
                case ')':
                    if(!openBrackets.empty()) {
                        openBrackets.pop();
                    } else if(!starWars.empty()) {
                        starWars.pop();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        
        if(!openBrackets.empty()) {
            if(starWars.empty()) {
                return false;
            } else {
                while(!openBrackets.empty() and !starWars.empty() and starWars.top() > openBrackets.top()) {
                    starWars.pop();
                    openBrackets.pop();
                }
            }
        }
        
        return openBrackets.empty();
    }
};