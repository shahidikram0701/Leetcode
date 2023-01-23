// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dfs = maxAreaOfIslandDFS(grid);
        int bfs = maxAreaOfIslandBFS(grid);
        
        return bfs;
    }
    
    int maxAreaOfIslandDFS(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxIsland = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    int island_size = destroyIsland(grid, n, m, i, j);
                    if(island_size > maxIsland) {
                        maxIsland = island_size;
                    }
                }
            }
        }
        
        return maxIsland;
    }
    
    int destroyIsland(vector<vector<int>>& grid, int r, int c, int i, int j) {
        if(i < 0 or i >= r or j >= c or j < 0) {
            return 0;
        }
        if(grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + destroyIsland(grid, r, c, i + 1, j) + destroyIsland(grid, r, c, i, j + 1) + destroyIsland(grid, r, c, i, j - 1) + destroyIsland(grid, r, c, i - 1, j);
    }
    
    int maxAreaOfIslandBFS(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxIsland = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    grid[i][j] = 0;
                    int island_size = 0;
                    while(!q.empty()) {
                        auto p = q.front();
                        island_size++;
                        q.pop();
                        int x = p.first;
                        int y = p.second;
                    
                        // push up if 1
                        if(x-1 >= 0 and grid[x-1][y] == 1) {
                            q.push(make_pair(x-1, y));
                            grid[x-1][y] = 0;
                        }
                        // push down if 1
                        if(x+1 < n and grid[x+1][y] == 1) {
                            q.push(make_pair(x+1, y));
                            grid[x+1][y] = 0;
                        }
                        // push left if 1
                        if(y-1 >= 0 and grid[x][y-1] == 1) {
                            q.push(make_pair(x, y-1));
                            grid[x][y-1] = 0;
                        }
                        // push right if 1
                        if(y+1 < m and grid[x][y+1] == 1) {
                            q.push(make_pair(x, y+1));
                            grid[x][y+1] = 0;
                        } 
                    }
                    if(island_size > maxIsland) {
                        maxIsland = island_size;
                    }
                }
            }
        }
        
        return maxIsland;
    }
};