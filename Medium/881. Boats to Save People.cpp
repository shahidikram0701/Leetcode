// https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int boats = 0;
        
        while(l < r) {
            if(people[l] + people[r] <= limit) {
                ++l;
                --r;
            }
            else {
                --r;
            }
            boats++;
        }
        
        if(l == r) {
            boats++;
        }
        
        return boats;
    }
};