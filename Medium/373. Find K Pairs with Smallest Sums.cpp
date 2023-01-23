// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comparator = [](pair<int, int>& a, pair<int, int>& b) { return a.first + a.second > b.first + b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> heap(comparator);
        
        for(int i = 0; i < nums1.size() and i < k; ++i) {
            for(int j = 0; j < nums2.size() and j < k; ++j) {
                heap.push(make_pair(nums1[i], nums2[j]));
            }
        }
        
        vector<vector<int>> ans;
        int n = heap.size();
        for(int i = 0; i < n and i < k; ++i) {
            pair<int, int> top = heap.top();
            heap.pop();
            ans.emplace_back(vector<int>{ top.first, top.second });
        }
        
        return ans;
    }
};