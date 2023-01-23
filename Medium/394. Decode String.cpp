// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> count;
        
        int i = 0;
        
        while(i < s.length()) {
            if(s[i] == '[') {
                string ss = "";
                
                ss += s[i];
                st.push(ss);
                ++i;
            } else if(isdigit(s[i])) {
                string num = "";
                while(isdigit(s[i])) {
                    num += s[i];
                    ++i;
                }
                count.push(stoi(num));
            } else if(s[i] == ']') {
                string ss = "";
                while(!st.empty() and st.top() != "[") {
                    ss = st.top() + ss;
                    st.pop();
                }
                st.pop();
                string replicated = "";
                int num = count.top();
                count.pop();
                for(int j = 0; j < num; ++j) {
                    replicated += ss;
                }
                st.push(replicated);
                ++i;
            } else {
                string ss = "";
                if(!st.empty() and st.top() != "[") {
                    ss = st.top();
                    st.pop();
                }
                st.push(ss + s[i]);
                ++i;
                
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
        
    }
    
    
};