// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        while(!q.empty()) {
            pair<int, int> zeroWalaCell = q.front();
            int i = zeroWalaCell.first;
            int j = zeroWalaCell.second;
            q.pop();
            // up wala neighbour
            if(i - 1 >= 0 and ans[i-1][j] > (ans[i][j] + 1)) {
                ans[i-1][j] = ans[i][j] + 1;
                q.push(make_pair(i-1, j));
            }
            // down wala neighbour
            if(i + 1 < m and ans[i+1][j] > (ans[i][j] + 1)) {
                ans[i+1][j] = ans[i][j] + 1;
                q.push(make_pair(i+1, j));
            }
            // left wala neighbour
            if(j - 1 >= 0 and ans[i][j-1] > (ans[i][j] + 1)) {
                ans[i][j-1] = ans[i][j] + 1;
                q.push(make_pair(i, j-1));
            }
            // right wala neighbour
            if(j + 1 < n and ans[i][j+1] > (ans[i][j] + 1)) {
                ans[i][j+1] = ans[i][j] + 1;
                q.push(make_pair(i, j+1));
            }
        }
        
        return ans;
    }
};