// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> counts;

        for(int t: time) {
            if(counts.find(t) == counts.end()) {
                counts[t] = 0;
            }
            counts[t]++;
        }
        int ans = 0;
        for(int i = 0; i < time.size(); ++i) {
            int currenttime = time[i];
            counts[currenttime]--;

            for(int j = 1; j <= 16; ++j) {
                int multiple = 60 * j;
                int diff = (multiple - currenttime);

                if(counts.find(diff) != counts.end() and counts[diff] > 0) {
                    // cout << currenttime << " + " << diff << "::" << multiple << endl;
                    ans += counts[diff];
                }
            }
            
        }

        return ans;
    }
};