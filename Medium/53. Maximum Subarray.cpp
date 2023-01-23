class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int subArraySum = 0;
        
        for(int i=0; i < nums.size(); ++i) {
            if(subArraySum < 0) {
                subArraySum = nums[i];
            }
            else {
                subArraySum += nums[i];
            }
            if(subArraySum > maxSum) {
                maxSum = subArraySum;
            }
        }
        return maxSum ;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int finalSum = INT_MIN;
        int sum = INT_MIN;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum = (sum == INT_MIN ? nums[i] : max(sum + nums[i], nums[i]));
            finalSum = max(sum, finalSum);
        }
        
        return finalSum;
    }
};