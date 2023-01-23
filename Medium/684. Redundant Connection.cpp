// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> sets(n+1, -1);
        vector<int> ans;
        
        for(auto e: edges) {
            int v1 = e[0];
            int v2 = e[1];
            
            int set1 = _find(v1, sets);
            int set2 = _find(v2, sets);
            
            if(set1 == set2) {
                ans = e;
            }
            else {
                _union(set1, set2, sets);
            }
        }
        
        return ans;
    }
    
    int _find(int v, vector<int>& sets) {
        if(sets[v] == -1) {
            return v;
        }
        return _find(sets[v], sets);
    }
    
    void _union(int set1, int set2, vector<int>& sets) {
        int childSet = min(set1, set2);
        int parentSet = max(set1, set2);
        
        sets[childSet] = parentSet;
    }
    
};