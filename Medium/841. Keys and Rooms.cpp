// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        dfs(rooms, 0, visited);
        
        if(std::any_of(visited.begin(), visited.end(), [](bool b) {return !b;})) {
            return false;
        }
        return true;
        
    }
    
    void dfs(vector<vector<int>>& rooms, int v, vector<bool>& visited) {
        visited[v] = true;
        
        vector<int> keys = rooms[v];
        
        for(int key: keys) {
            if(!visited[key]) {
                dfs(rooms, key, visited);
            }
        }
    }
};