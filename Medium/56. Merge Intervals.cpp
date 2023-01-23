class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        auto comparator = [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] >= b[1];
            }
            return a[0] > b[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> h(comparator);
        
        
        for(auto i: intervals) {
            h.push(i);
        }
        
        int prevX = h.top()[0];
        int prevY = h.top()[1];
        h.pop();
        while(!h.empty()) {
            vector<int> i = h.top();
            h.pop();
            
            if(overlaps(prevX, prevY, i[0], i[1])) {
                prevY = max(prevY, i[1]);
            } else {
                ans.emplace_back(vector<int>{prevX, prevY});
                prevX = i[0];
                prevY = i[1];
            }
            
        }
        if(prevX != -1) {
             ans.emplace_back(vector<int>{prevX, prevY});
        }
        
        return ans;
    }
    
    bool overlaps(int x1, int y1, int x2, int y2) {
        if(x1 <= x2 and x2 <= y1) {
            return true;
        }
        return false;
    }
};
