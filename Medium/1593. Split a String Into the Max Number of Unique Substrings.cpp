// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> splits;
        return recur(s, 0, s.length(), splits);
    }

    int recur(string s, int i, int n, unordered_set<string>& splits) {
        if(i >= n) {
            return splits.size();
        }

        string substr = "";
        int ans = 1;
        for(int j = i; j < n; ++j) {
            substr += s[j];
            if(splits.find(substr) == splits.end()) {
                splits.insert(substr);
                ans = max(ans, recur(s, j + 1, n, splits));
                splits.erase(substr);
            } 
        }

        return ans;

    }
};