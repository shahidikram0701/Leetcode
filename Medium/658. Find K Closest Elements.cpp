// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        sort(arr.begin(), arr.end(), [&x](int a, int b) {
            return abs(a - x) == abs(b - x) ? a < b : abs(a - x) < abs(b - x);
        });   

        int i = 0;
        while(i < arr.size() and i < k) {
            ans.push_back(arr[i]);
            ++i;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};