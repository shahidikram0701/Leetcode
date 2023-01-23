// https://leetcode.com/problems/matchsticks-to-square/

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(), matchsticks.rend());
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        vector<int> sides(4, 0);
        return sum % 4 == 0 ? recur(matchsticks, 0, sum/4, sides): false;
    }

    bool recur(vector<int>& matchsticks, int i, int side, vector<int>& sides) {
        if(i >= matchsticks.size()) {
            return sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == sides[3];
        }
        if(sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == side) {
            return true;
        } 

        bool ans = false;

        for(int j = 0; j < 4; ++j) {
            if(sides[j] + matchsticks[i] <= side) {
                sides[j] += matchsticks[i];
                ans = ans or recur(matchsticks, i + 1, side, sides);
                sides[j] -= matchsticks[i];
            }
            
        }

        return ans;

    }
};