// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> minimas(m, vector<int>(n, INT_MAX));
        
        
        int totalTime = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) {
                    minimas[i][j] = 0;
                } else if(grid[i][j] == 2) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int time = 0;
                    minimas[i][j] = 0;
                    queue<pair<int, pair<int, int>>> q;
                    q.push(make_pair(0, make_pair(i, j)));
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int t = p.first;
                        auto interval = p.second;
                        int i_ = interval.first;
                        int j_ = interval.second;
                        
                        if(i_ - 1 >= 0 and !visited[i_ - 1][j_] and grid[i_ - 1][j_] == 1 and minimas[i_ - 1][j_] > t + 1) {
                            visited[i_ - 1][j_] = true;
                            q.push(make_pair(t + 1, make_pair(i_ - 1, j_)));
                            minimas[i_ - 1][j_] = t + 1;
                        }
                         if(i_ + 1 < m and !visited[i_ + 1][j_] and grid[i_ + 1][j_] == 1 and minimas[i_ + 1][j_] > t + 1) {
                            visited[i_ + 1][j_] = true;
                            q.push(make_pair(t + 1, make_pair(i_ + 1, j_)));
                            minimas[i_ + 1][j_] = t + 1;
                        }
                        if(j_ - 1 >= 0 and !visited[i_][j_ - 1] and grid[i_][j_ - 1] == 1 and minimas[i_][j_ - 1] > t + 1) {
                            visited[i_][j_ - 1] = true;
                            q.push(make_pair(t + 1, make_pair(i_, j_ - 1)));
                            minimas[i_][j_- 1] = t + 1;
                        }
                        
                        if(j_ + 1 < n and !visited[i_][j_ + 1] and grid[i_][j_ + 1] == 1 and minimas[i_][j_ + 1] > t + 1) {
                            visited[i_][j_ + 1] = true;
                            q.push(make_pair(t + 1, make_pair(i_, j_ + 1)));
                            minimas[i_][j_ + 1] = t + 1;
                        }   
                    }
                    
                    // totalTime = max(totalTime, time);
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                maxi = max(maxi, minimas[i][j]);
            }
        }
        return maxi == INT_MAX ? -1 : maxi;
    }
};