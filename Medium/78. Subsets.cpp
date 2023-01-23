// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subans;
        recur(nums, 0, ans, subans);
        ans.emplace_back(vector<int>{});
        return ans;
    }

    void recur(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& subans) {
        if(i >= nums.size()) {
            if(subans.size() > 0)
                ans.emplace_back(subans);
            return;
        }

        recur(nums, i+1, ans, subans);
        vector<int> subans2(subans);
        subans2.emplace_back(nums[i]);
        recur(nums, i+1, ans, subans2);
    }
};