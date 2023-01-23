// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    
    bool check_if_anagram(unordered_map<char, int>& mapping, unordered_map<char, int>& running_map) {
        for(auto p: mapping) {
            if(running_map[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mapping;
        
        for(char c: p) {
            if(mapping.find(c) == mapping.end()) {
                mapping[c] = 1;
            }
            else {
                mapping[c] = mapping[c] + 1;
            }
        }
        int j = 0;
        unordered_map<char, int> running_map;
        int plen = p.length();
        while(j < s.length()) {
             if(j >= plen) {
                running_map[s[j-plen]] = running_map[s[j-plen]] - 1;
            }
            if(running_map.find(s[j]) == running_map.end()) {
                running_map[s[j]] = 1;
            } else {
                running_map[s[j]] = running_map[s[j]] + 1;
            }
            if(check_if_anagram(mapping, running_map)) {
                ans.emplace_back(j-plen+1);
            }
            ++j;
        }
        return ans;
    }
};