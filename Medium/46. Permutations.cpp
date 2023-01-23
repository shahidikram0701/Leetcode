class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& numnums) {
        vector<bool> v(numnums.size(), false); 
        vector<int> combi;
        recur(numnums, combi, v);
        return ans;
        
    }
    
    void recur(vector<int> numnums, vector<int>& combi, vector<bool> &v) {
        if(combi.size() == numnums.size()) {
            ans.emplace_back(combi);
        }
        for(int j = 0; j < numnums.size(); ++j) {
            if( v[j] == true ) {
                continue;
            } 
            combi.emplace_back(numnums[j]);
            v[j] = true;
            recur(numnums, combi, v);
            combi.pop_back();
            v[j] = false;
        }
        
    }
};


