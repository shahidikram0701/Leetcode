// #define METHOD1

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        #ifdef METHOD1
            return threeSumMethod1(nums);
        #endif
                
        return threeSumMethod2(nums);
    }
    
    vector<vector<int>> threeSumMethod1(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, int> thirdElementMap;
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); ++i) {
            thirdElementMap[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size() - 2; ++i){
            for(int j = i+1; j < nums.size() - 1; ++j){
                int thirdElementVal = -(nums[i] + nums[j]);
                if(thirdElementMap.find(thirdElementVal) != thirdElementMap.end()) {
                    int index = thirdElementMap[thirdElementVal]; 
                    // Take only combinations where index of third element is greater than the previous two
                    if(index > j && index > i){
                        ans.emplace_back(vector<int>{nums[i], nums[j], thirdElementVal});
                    } 
                }
                // If equal, move forward till the next new element
                while(j < nums.size() - 1 and nums[j+1] == nums[j]) {
                    ++j;
                }
                while(i < nums.size() - 2 and nums[i+1] == nums[i]) {
                    ++i;
                }
            }
        }
        return ans;
    }
    vector<vector<int>> threeSumMethod2(vector<int>& nums) {
        // Two pointer method
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i=0; i<nums.size(); i++) {
            // to avoid same i considered multiple times
            if ((i>0) && (nums[i]==nums[i-1]))
                continue;
            int l = i+1, r = nums.size()-1;
            while (l<r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s>0) r--;
                else if (s<0) l++;
                else {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    // To avoid same l and r pair being generated repeatedly
                    while (l+1<r and nums[l]==nums[l+1]) l++;
                    while (r-1>l and nums[r]==nums[r-1]) r--;
                    l++; r--; // needed because it will be equal when we break out of loop
                }
            }
        }
        return res;  
    }
    
};