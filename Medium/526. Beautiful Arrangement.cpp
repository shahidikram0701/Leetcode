// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int countArrangement(int n) {
        unordered_map<int, bool> m;
        for(int i = 1; i <= n; ++i) {
            m[i] = true;
        }
        return recur(n, 1, m);
    }
    
    int recur(int n, int i, unordered_map<int, bool>& m) {
        if(i > n) {
            return 1;
        }
        
        int count = 0;
        for(int j = 1; j <= n; ++j) {
            if(m[j] and (j % i == 0 or i % j == 0)) {
                m[j] = false;
                count += recur(n, i+1, m);
                m[j] = true;
            }
            
        }
        return count;
    }
};