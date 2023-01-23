// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool traverseWord(string& s, string& cmp, int index){
        int i=0, size = cmp.size();
        while(i<size && s[index] == cmp[i]) {
            index++;
            i++;
        };
        if(i==size){
            return true;
        }
        return false;
    }
    bool traverseString(string& s, int index, unordered_map<char, vector<string>> &m, unordered_map<int, bool>& dp){
        if(index == s.size()){
            return true;
        }
        bool res = false;
        vector<string> words = m[s[index]];
        for(string word: words){
            if(traverseWord(s, word, index)){
                if(dp.find(index + word.size())!=dp.end()){
                    res = res || dp[index + word.size()];
                }
                else {
                    bool val = traverseString(s, index + word.size(), m, dp);
                    res = res || val;
                    dp[index] = res;
                }
            }
        }
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> m;
        for(string word: wordDict){
            m[word[0]].push_back(word);
        }
        unordered_map<int, bool> dp;
        return traverseString(s, 0, m, dp);
    }
};