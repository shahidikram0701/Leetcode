// https://leetcode.com/problems/task-scheduler/

class Solution {
public:  
   int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char, int> m;
       for(char task: tasks){
           if(m.find(task) == m.end()) {
               m[task] = 0;
           }
           m[task]++;
       } 

       auto comp = [&m](char a, char b) {
           return m[a] < m[b];
       };

       priority_queue<char, vector<char>, decltype(comp)> q(comp);

       for(auto p: m) {
           q.push(p.first);
       }

       int ans = 0;

       while(!q.empty()) {
           int i = 0;
           vector<char> reserve;
        //    cout << "________" << endl;
           while(i <= n) {
               if(!q.empty()) {
                    char c = q.top();
                    // cout << c << endl;
                    q.pop();
                    ans++;
                    --m[c];
                    
                    reserve.push_back(c);
                    
               }
               i++;
           }
           if(reserve.size() > 0) {
               bool addIdle = false;
               for(char c: reserve) {
                   if(m[c] > 0) {
                       addIdle = true;
                       q.push(c);
                   }
               }
               if(addIdle){
                   ans += ((n + 1) - reserve.size());
               }
           }

        //    cout << "ans = " << ans << endl;
       }

       return ans;


   }
};