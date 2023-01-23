// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<int> ans;
        vector<int> uniqueNums;
        for(int num: nums) {
            if(countMap.find(num) == countMap.end()) {
                countMap[num] = 1;
                uniqueNums.emplace_back(num);
             } else {
                countMap[num]++;
            }
        }
        
        auto comparator = [&countMap](int& a, int& b){ return countMap[a] < countMap[b]; };
        
        priority_queue<int, vector<int>, decltype(comparator)> heap(comparator);
        for(int num: uniqueNums) {
            heap.push(num);
        }
        
        int _k = 0;
        while(!heap.empty() and _k < k) {
            int top = heap.top();
            ans.emplace_back(top);
            heap.pop();
            ++_k;
        }
        
        return ans;
    }
};

// checkout quickselect approach: https://leetcode.com/problems/top-k-frequent-elements/solutions/646157/top-k-frequent-elements/

