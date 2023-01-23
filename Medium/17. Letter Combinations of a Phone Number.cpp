class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return {};
        }
        vector<string> ans;
        unordered_map<char, string> phone
        {
                           {'2', "abc"}, {'3', "def"}, 
             {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        recur(digits, 0, phone, ans, "");
        return ans;
    }
    
    void recur(string digits, int i, unordered_map<char, string>& phone, vector<string>& ans, string message) {
        if(i == digits.length()) {
            ans.emplace_back(message);
            return;
        }
        string currentPossibilities = phone[digits[i]];
        for(char c: currentPossibilities) {
            recur(digits, i+1, phone, ans, message+c);
        }
    }
};