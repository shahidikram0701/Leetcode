// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        vector<int> degree(n, 0);

        vector<vector<int>> graph(n, vector<int>{});

        vector<int> ans;

        for(auto edge: edges) {
            int v1 = edge[0];
            int v2 = edge[1];

            degree[v1]++;
            degree[v2]++;

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        queue<pair<int, int>> q;

        for(int v = 0; v < n; ++v) {
            if(degree[v] == 1) {
                q.push(make_pair(1, v));
            }
        }
        
        int curr_level = 0;
        while(!q.empty()) {
            int level = q.front().first;
            int node = q.front().second;

            q.pop();
            
            if(level > curr_level) {
                ans.clear();
                curr_level = level;
            }

            ans.push_back(node);
            
            for(int v: graph[node]) {
                degree[v]--;

                if(degree[v] == 1) {
                    q.push(make_pair(level+1, v));
                }
            }
        }

        return ans;
    }
};