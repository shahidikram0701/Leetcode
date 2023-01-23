// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); ++i) {
            int currentElement = abs(nums[i]);
            
            if(nums[currentElement - 1] < 0) {
                ans.emplace_back(currentElement);
            }
            nums[currentElement - 1] *= -1;
        }
        
        return ans;
    }
};