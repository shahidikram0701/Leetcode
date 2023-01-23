// https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> closestPersonDistance(n, INT_MAX);
        
        int maxDistance = INT_MIN;
        
        for(int i = 0; i < n; ++i) {
            if(seats[i]) {
                closestPersonDistance[i] = 0;
            } else {
                if(i - 1 >= 0 and closestPersonDistance[i-1] != INT_MAX) {
                    closestPersonDistance[i] = closestPersonDistance[i - 1] + 1;
                }
            }
        }
        
        for(int i = n - 1; i >= 0; --i) {
            if(seats[i]) {
                closestPersonDistance[i] = 0;
            } else {
                if(i + 1 < n and closestPersonDistance[i+1] != INT_MAX) {
                    closestPersonDistance[i] = min(closestPersonDistance[i], closestPersonDistance[i+1] + 1);
                }
            }
            if(closestPersonDistance[i] > maxDistance) {
                maxDistance = closestPersonDistance[i];
            }
        }
                
       return maxDistance;
    }
};