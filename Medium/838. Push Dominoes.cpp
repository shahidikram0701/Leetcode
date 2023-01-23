// https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        char prev = '.';
        for(int i = n - 1; i >= 0; --i) {
            if(dominoes[i] == 'R') {
                left[i] = 1;
                prev = dominoes[i];
            } else {
                if(prev == 'L' or dominoes[i] == 'L') {
                    left[i] = -1;
                    prev = 'L';
                } else {
                    left[i] = 0;
                    prev = dominoes[i];
                }
            
            }
        }
        
        prev = '.';
        for(int i = 0; i < n; ++i) {
            if(dominoes[i] == 'L') {
                right[i] = -1;
                prev = dominoes[i];
            } else {
                if(prev == 'R' or dominoes[i] == 'R') {
                    right[i] = 1;
                    prev = 'R';
                } else {
                    right[i] = 0;
                    prev = dominoes[i];
                }
            }
            
        }
        
//         for(int l: left) {
//             cout << l << "; ";
//         } 
//         cout << endl;
        
//         for(int r: right) {
//             cout << r << "; ";
//         } 
//         cout << endl;
        
        vector<int> pre_ans(n, 0);
        
        int l = 0;
        
        vector<pair<int, int>> conflicts;
        
        while(l < n) {
            if(left[l] == right[l]) {
                pre_ans[l] = left[l];
            } else {
                if(left[l] + right[l] > 0) {
                    pre_ans[l] = 1;
                    
                } else if(left[l] + right[l] < 0) {
                    pre_ans[l] = -1;
                } else {
                    int start = l;
                    while(l < n and left[l] + right[l] == 0) {
                        ++l;
                    }
                    int end = --l;
                    conflicts.emplace_back(make_pair(start, end));
                }
            }
            ++l;
        }
        
        for(auto p: conflicts) {
            int l = p.first;
            int r = p.second;
            
            while(l < r) {
                pre_ans[l] = pre_ans[l-1];
                pre_ans[r] = pre_ans[r+1];
                
                ++l;
                --r;
            }
        }
        string ans = "";
    
        for(int i: pre_ans) {
            if(i == 1) {
                ans += 'R';
            } else if(i == -1) {
                ans += 'L';
            } else {
                ans += '.';
            }
        }
        
        return ans;
        
    }
};