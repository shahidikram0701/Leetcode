// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comparator = [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), comparator);

        auto prev = vector<int>{};
        int ans = 0;

        for(auto i: intervals) {
            if(prev.size() == 0) {
                prev = i;
                continue;
            }

            if(i[0] >= prev[0] and i[0] < prev[1]) {
                ans += 1;
                if(i[1] < prev[1]) {
                    prev = i;
                }
            } else {
                prev = i;
            }
        }

        return ans;
    }

};