class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        if(n == 1) {
            return 0;
        }
        while(i < n) {
            if(i + nums[i] >= n - 1) {
                return ans + 1;
            }  
            int maxi = 0;
            int jumpToIndex = i;
            for(int j = i; j <= i + nums[i] ; ++j) {
                if(j + nums[j] > maxi) {
                    maxi = j + nums[j];
                    jumpToIndex = j;
                }
            }
            ans += 1;
            i = jumpToIndex;
        }
        
        return ans;
    }
};