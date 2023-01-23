// https://leetcode.com/problems/pacific-atlantic-water-flow/

    class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> visitedPacific(m, vector<int>(n, 0));
        vector<vector<int>> visitedAtlantic(m, vector<int>(n, 0));
        
        vector<vector<int>> ans;
        
        // pacific
        for(int i = 0; i < m; ++i) {
            if(!visitedPacific[i][0]) {
                markAllConnectedComponents(heights, m, n, i, 0, visitedPacific);
            }
        }
        for(int j = 0; j < n; ++j) {
            if(!visitedPacific[0][j]) {
                markAllConnectedComponents(heights, m, n, 0, j, visitedPacific);
            }
        }
        
        // atlantic
        for(int i = 0; i < m; ++i) {
            if(!visitedAtlantic[i][n-1]) {
                markAllConnectedComponents(heights, m, n, i, n-1, visitedAtlantic);
            }
        }
        for(int j = 0; j < n; ++j) {
            if(!visitedAtlantic[m-1][j]) {
                markAllConnectedComponents(heights, m, n, m-1, j, visitedAtlantic);
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visitedPacific[i][j] and visitedAtlantic[i][j])
                    ans.emplace_back(vector<int>{ i, j });
            }
        }
        
        return ans;
           
    }
    
    void markAllConnectedComponents(vector<vector<int>>& heights, int m, int n, int i, int j, vector<vector<int>>& visited) {
        if(i < 0 or j < 0 or i >= m or j >= n) {
            return;
        }
        visited[i][j] = 1;
        bool upCond = (i - 1 >= 0) and visited[i-1][j] != 1 and heights[i-1][j] >= heights[i][j];
        bool downCond = (i + 1 < m) and visited[i+1][j] != 1 and heights[i+1][j] >= heights[i][j];
        bool leftCond = (j - 1 >= 0) and visited[i][j-1] != 1 and heights[i][j-1] >= heights[i][j];
        bool rightCond = (j + 1 < n) and visited[i][j+1] != 1 and heights[i][j+1] >= heights[i][j];
        
        if(upCond) {
            markAllConnectedComponents(heights, m, n, i-1, j, visited);
        }
        if(downCond) {
            markAllConnectedComponents(heights, m, n, i+1, j, visited);
        }
        if(rightCond) {
            markAllConnectedComponents(heights, m, n, i, j+1, visited);
        }
        if(leftCond) {
            markAllConnectedComponents(heights, m, n, i, j-1, visited);
        }
    }
};