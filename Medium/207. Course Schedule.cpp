// https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        createGraph(prerequisites, graph);
        
        vector<bool> visited(numCourses, false);
        
        bool ans = false;
        set<int> recStack;
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i]) {
                bool isCyclic = checkCycle(graph, i, visited, recStack);
                ans = ans or isCyclic;
            }
        }
        return !ans;
    }
    
    void createGraph(vector<vector<int>>& pr, unordered_map<int, vector<int>>& graph) {
        int n = pr.size();
        for(int i = 0; i < n; ++i) {
            int course = pr[i][0];
            int pre_course = pr[i][1];
            graph[course].emplace_back(pre_course);
        }
    }
    
    bool checkCycle(unordered_map<int, vector<int>>& graph, int course, vector<bool>& visited, set<int>& recStack) {
        if(visited[course] and recStack.find(course) != recStack.end()) {
            return true;
        }
        if(visited[course]) {
            return false;
        }
        recStack.insert(course);
        visited[course] = true;
        
        int isCyclic = false;
        for(int pre_course: graph[course]) {
            isCyclic = isCyclic or checkCycle(graph, pre_course, visited, recStack);
        }
        recStack.erase(course);
        return isCyclic;
    }
};