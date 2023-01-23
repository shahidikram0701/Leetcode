// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> heap;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(k <= 0) {
                    if(matrix[i][j] < heap.top()) {
                        heap.pop();
                        heap.push(matrix[i][j]);
                    }
                } else {
                    heap.push(matrix[i][j]);
                    --k;
                }
            }
        }
        
        return heap.top();
    }
};

// Binary search approach: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/