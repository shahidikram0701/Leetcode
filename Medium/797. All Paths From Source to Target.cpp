// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> ans;
        vector<int> path{0};
        findPath(graph, 0, path, ans, n - 1);
            
        return ans;
        
    }
    
    void findPath(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& ans, int last) {
        if(node == last) {
            ans.emplace_back(path);
            return;
        }
        for(int i: graph[node]) {
            path.emplace_back(i);
            findPath(graph, i, path, ans, last);
            path.pop_back();
        }
    }
};