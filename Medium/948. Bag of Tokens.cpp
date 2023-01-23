// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size() - 1;
        int score = 0;
        int _power = power;
        
        while(l <= r) {
            if(tokens[l] <= _power) {
                ++score;
                _power -= tokens[l];
                ++l;
            } else {
                if(l != r and score >= 1) {
                    --score;
                    _power += tokens[r];
                    --r;
                } else {
                    break;
                }
            }
        }
        
        return score;
    }
};