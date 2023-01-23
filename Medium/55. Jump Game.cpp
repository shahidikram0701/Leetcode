class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_index = n - 1;
        
        for(int i = n-2; i >= 0; --i) {
            if(nums[i] >= abs(last_index - i)) {
                last_index = i;
            }
        }
        return !last_index;
    }
};