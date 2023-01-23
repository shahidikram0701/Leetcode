// https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(sum < 0) {
                start = i;
                sum = 0;
            }
            sum = sum + gas[i] - cost[i];
        }
        
        int i = 0;
        int j = start;
        int running_sum = gas[j];

        while(i < n) {
            if(running_sum < cost[j]) {
                return -1;
            }
            running_sum = (running_sum - cost[j]) + gas[(j + 1) % n];
            j = (j + 1) % n;
            i = (i + 1);
        }

        return start;
    }
};