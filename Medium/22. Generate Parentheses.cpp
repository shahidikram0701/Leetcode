class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur(n, n, "", ans);
        return ans;
    }
    
    void recur(int left, int right, string pattern, vector<string>& ans) {
        if(left == 0 and right == 0) {
            ans.emplace_back(pattern);
            return;
        }
        if(right < left) {
            return;
        }
        if(left < 0 or right < 0) {
            return;
        } 

        recur(left-1, right, pattern+"(", ans);
        recur(left, right-1, pattern+")", ans);
    }
};