// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return search(matrix, m, n, target, 0, (m * n - 1));
    }
    
    bool search(vector<vector<int>>& matrix, int m, int n, int target, int l, int r) {
        if(l > r) {
            return false;
        } 
        int mid = l + ((r - l) / 2);
        
        // a[i][j] = a + (i * n) + j
        int i = mid / n;
        int j = mid - (i * n);
        
        if(matrix[i][j] == target) {
            return true;
        }
        if(matrix[i][j] < target) {
            return search(matrix, m, n, target, mid + 1, r);
        } 
        return search(matrix, m, n, target, l, mid -1);
    }
};