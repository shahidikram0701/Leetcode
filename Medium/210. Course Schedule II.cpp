// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>{});
        vector<int> ans;
        queue<int> q;

        for(auto p: prerequisites) {
            int v1 = p[0];
            int v2 = p[1];

            indegree[v1]++;
            graph[v2].push_back(v1);

        }

        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int i: graph[node]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        

        if(ans.size() == numCourses) {
            return ans;
        } 

        return {};
    }
};