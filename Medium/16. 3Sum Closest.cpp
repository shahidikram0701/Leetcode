class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int mini = INT_MAX;
        for(int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;
            
            while(l < r) {
                int val = nums[i] + nums[l] + nums[r];
                if(abs(target - val) < mini) {
                    mini = abs(target - val);
                    ans = val;
                }
                if(val < target) {
                    l++;
                } else if (val > target) {
                    r--;
                } else {
                    return ans;
                }
            }
        }
        
        return ans;
    }
};