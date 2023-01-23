// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                bool found = recur(board, i, j, m, n, word, 0, visited);
                if(found) {
                    return found;
                }
            }
        }
        return false;
    }
    
    
    bool recur(vector<vector<char>>& board, int i, int j, int m, int n, string word, int wordMatchIndex, vector<vector<int>>& visited) {
        if(wordMatchIndex == word.length()) {
            return true;
        }
        if(i >= m or i < 0 or j < 0 or j >= n) {
            return false;
        }
        if(visited[i][j]) {
            return false;
        }
        visited[i][j] = 1;
        if(board[i][j] != word[wordMatchIndex]) {
            visited[i][j] = 0;
            return false;
        }
        int up = recur(board, i-1, j, m, n, word, wordMatchIndex+1, visited);
        int down = recur(board, i+1, j, m, n, word, wordMatchIndex+1, visited);
        int right = recur(board, i, j-1, m, n, word, wordMatchIndex+1, visited);
        int left = recur(board, i, j+1, m, n, word, wordMatchIndex+1, visited);
        
        visited[i][j] = 0;
        return up or down or left or right;
    }
};