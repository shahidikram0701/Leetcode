// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int n: nums) {
            s.insert(n);
        }
        
        int ans = 0;
        
        for(int n: nums) {
            if(s.find(n-1) == s.end()) {
                int i = n;
                while(s.find(i) != s.end()) {
                    ++i;
                }
                ans = max(ans, i - n);
            }
        }
        
        return ans;
    }
};