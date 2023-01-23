// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        auto comparator = [](vector<int>& a, vector<int>& b) {
            int distanceA = a[0] * a[0] + a[1] * a[1];
            int distanceB = b[0] * b[0] + b[1] * b[1];
            
            return distanceB < distanceA;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> heap(comparator);
        
        for(auto point: points) {
            heap.push(point);
        }
        
        for(int i = 0; i < k; ++i) {
            ans.emplace_back(heap.top());
            heap.pop();
        }
        
        return ans;
    }
};