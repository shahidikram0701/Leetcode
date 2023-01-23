class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int max_area = INT_MIN;
        
        while(l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            
            int area = h * w;
            
            max_area = area > max_area ? area : max_area;
            
            if(height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        
        return max_area;
    }
};