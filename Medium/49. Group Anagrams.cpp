class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<char, int> mapping = {{'a', 2}, {'b', 3}, {'c', 5}, {'d', 7}, {'e', 9}, {'f', 11}, {'g', 13}, {'h', 17}, {'i', 19}, {'j', 23}, {'k', 31}, {'l', 37}, {'m', 41}, {'n', 43}, {'o', 47}, {'p', 53}, {'q', 59}, {'r', 61}, {'s', 67}, {'t', 71}, {'u', 73}, {'v', 79}, {'w', 83}, {'x', 89}, {'y', 97}, {'z', 101}};
        
        map<long, vector<string>> groups;
        
        for(string str: strs) {
            long val = 1;
            for(char c: str) {
                val = (val * mapping[c]) % INT_MAX;
            }
            if(groups.find(val) == groups.end()) {
                groups[val] = {str};
            }
            else {
                groups[val].emplace_back(str);
            }
        }
        
        for(auto p: groups) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
};