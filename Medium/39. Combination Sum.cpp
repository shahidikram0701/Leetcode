class Solution {
public:
    void recur(vector<vector<int>>& ans, vector<int>& current, int sum, vector<int>& candidates, int i){
        if(i >= candidates.size() or sum < 0){
            return;
        }
        if(sum == 0){
            ans.push_back(current);
            return;
        }

       
        current.push_back(candidates[i]);
        sum = sum - candidates[i];
        recur(ans, current, sum, candidates, i);
        sum = sum + candidates[i];
        current.pop_back();
        
        recur(ans, current, sum, candidates, i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        recur(ans, current, target, candidates, 0);
        return ans;
    }
};