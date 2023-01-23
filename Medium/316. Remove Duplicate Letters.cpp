// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s1) {
        vector<int> str;
        unordered_map<int, int> m;
        string ans = "";

        unordered_set<int> hashset;

        for(char c: s1) {
            int c_ = int(c);
            str.push_back(c_);
            if(m.find(c_) == m.end()) {
                m[c_] = 0;
            }
            m[c_]++;
        }

        stack<int> s;
        

        for(int i: str) {
            if(s.empty()) {
                s.push(i);
                hashset.insert(i);
                m[i]--;
                continue;
            }
            while(!s.empty() and hashset.find(i) == hashset.end() and i < s.top() and m[s.top()] > 0) {
                // m[s.top()]--;
                hashset.erase(s.top());
                s.pop();
            }
            // cout << i << endl;
            if(hashset.find(i) == hashset.end()) {
                s.push(i);  
                hashset.insert(i);
            }
            m[i]--;
        }

        while(!s.empty()) {
            char c = char(s.top());
            ans += c;
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};