// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; (!ans and i < m and (n - 1 - i) >= 0); ++i) {
            int comparator = matrix[i][n-1-i];
            if(comparator == target) {
                ans = true;
            } else if (target < comparator) {
                // do binary search on row i
                ans = ans or searchRow(matrix, target, i, 0, n - 2 - i);
            } else {
                // do binary search on column n - 1 - i
                ans = ans or searchColumn(matrix, target, n - 1 - i, i + 1, m - 1);
            }
        }
        
        return ans;
    }
    
    bool searchRow(vector<vector<int>>& matrix, int target, int row, int l, int r) {
        if(l > r) {
            return false;
        }
        int mid = l + ((r - l) / 2);
        if(matrix[row][mid] == target) {
            return true;
        }
        if(matrix[row][mid] < target) {
            return searchRow(matrix, target, row, mid + 1, r);
        } 
        return searchRow(matrix, target, row, 0, mid - 1);
    }
    
    bool searchColumn(vector<vector<int>>& matrix, int target, int col, int l, int r) {
        if(l > r) {
            return false;
        }
        int mid = l + ((r - l) / 2);
        if(matrix[mid][col] == target) {
            return true;   
        }
        if(matrix[mid][col] < target) {
            return searchColumn(matrix, target, col, mid + 1, r);
        } 
        return searchColumn(matrix, target, col, 0, mid - 1);
    }
};

// Solution 2

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col-1;

        while(rowIndex<row && colIndex>=0){
            int element = matrix[rowIndex][colIndex];

            if(element == target){
                return 1;
            }

            else if (element > target){
                colIndex--;
            }
            else if(element < target){
                rowIndex++;
            }
        }
    return 0;
        
    }
};