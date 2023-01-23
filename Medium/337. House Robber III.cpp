// https://leetcode.com/problems/house-robber-iii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> dp;
        return recur(root, true, dp);    
    }

    int recur(TreeNode* root, bool canRob, unordered_map<TreeNode*, vector<int>>& dp) {
        if(root == NULL) {
            return 0;
        }

        if(dp.find(root) != dp.end() and dp[root][canRob] != -1) {
            return dp[root][canRob];
        }

        int rob = 0;
        int noRob = recur(root->left, true, dp) + recur(root->right, true, dp);

        if(canRob) {
            rob = root -> val + (recur(root->left, false, dp) + recur(root->right, false, dp)); 
        }

        if(dp.find(root) == dp.end()) {
            dp[root] = {-1, -1};
        }
        dp[root][canRob] = max(rob, noRob);

        return dp[root][canRob];
    }
};