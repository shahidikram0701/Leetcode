// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++count;
                    traverse_this_island(grid, i, j);
                }
            }
        }
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '-') {
                   grid[i][j] = 1;
                }
            }
        }
        
        return count;
    }
    
    void traverse_this_island(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ) {
            return;
        }
        if(grid[i][j] == '0' || grid[i][j] == '-') {
            return;
        }
        if(grid[i][j] == '1') {
            grid[i][j] = '-';
        }
        traverse_this_island(grid, i-1, j);
        traverse_this_island(grid, i+1, j);
        traverse_this_island(grid, i, j-1);
        traverse_this_island(grid, i, j+1);
    }
};