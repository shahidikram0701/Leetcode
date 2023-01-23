
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) {
            return 0;
        }
        unordered_map<char, int> positions;
        int l = 0;
        int r = l + 1;
        int count = 1;
        positions[s[l]] = l;
        
        int max_count = count;
        
        while(r < s.length()) {
            if(positions.find(s[r]) == positions.end()) {
                positions[s[r]] = r;
            }
            else {
                if(l <= positions[s[r]]) {
                    l = positions[s[r]] + 1;
                }
                positions[s[r]] = r;
            }
            count = r - l + 1;
            
            if(count > max_count) {
                max_count = count;
            }
            ++r;
        }
        
        return max_count;
    }
};