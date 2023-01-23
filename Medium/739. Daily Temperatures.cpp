// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; --i) {
            if(s.empty()) {
                s.push(i);
                continue;
            }
            while(!s.empty() and temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if(!s.empty()) {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }

        return ans;
    }
};