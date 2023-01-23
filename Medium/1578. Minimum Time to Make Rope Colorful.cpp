// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.length();

        int i = 0;
        char prev = '\0';
        int prev_cost = -1;
        while(i < n) {
            if(i == 0) {
                prev = colors[i];
                prev_cost = neededTime[i];
                ++i;
                continue;
            }

            if(colors[i] == prev) {
                int total = prev_cost;
                int maxi = prev_cost;
            
                while(colors[i] == prev) {
                    total += neededTime[i];
                    maxi = max(maxi, neededTime[i]);

                    ++i;
                }
                ans += (total - maxi);
                prev_cost = maxi;
            } else {
                prev = colors[i];
                prev_cost = neededTime[i];
                ++i;
            }

        }

        return ans;
    }
};