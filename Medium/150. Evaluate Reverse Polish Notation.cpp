// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       unordered_map<string, function<int (int, int) > > doStuff = { 
           { "+" , [] (int a, int b) { return a + b; } },
           { "-" , [] (int a, int b) { return a - b; } }, 
           { "*" , [] (int a, int b) { return a * b; } }, 
           { "/" , [] (int a, int b) { return a / b; } } 
       };
       for(string s: tokens){
           if(doStuff.find(s)==doStuff.end()){
               st.push(stoi(s));
           }
           else{
               int first = st.top();
               st.pop();
               int second = st.top();
               st.pop();
               st.push(doStuff[s](second, first));
           }
        }
        return st.top();
   }
};