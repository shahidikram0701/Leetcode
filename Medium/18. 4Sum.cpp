class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; ++i) {
            for(int j = i + 1; j < n-2; ++j) {
                int l = j + 1;
                int r = n - 1;
                
                int partial_sum = nums[i] + nums[j];
                long curr_target = (long)target - partial_sum;
                
                while(l < r) {
                    long sum = nums[l] + nums[r];
                    if(sum == curr_target) {
                        s.insert(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                    }
                    else if(sum < curr_target) {
                        ++l;
                    }
                    else {
                        --r;
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto e: s) {
            ans.emplace_back(e);
        }
        
        return ans;
        
    }
};