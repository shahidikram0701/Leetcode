// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> subans;
        
        recur(root, targetSum, subans, ans);
        return ans;
    }
    
    void recur(TreeNode* root, int targetSum, vector<int>& subans, vector<vector<int>>& ans) {
        if(root == NULL) {
            return;
        }
        
        subans.emplace_back(root->val);
        int newTarget = targetSum - root->val;
        
        if(root->left == NULL and root->right == NULL and newTarget == 0) {
            ans.emplace_back(subans);
            subans.pop_back();
            return;
        }
        
        recur(root->left, newTarget, subans, ans);
        recur(root->right, newTarget, subans, ans);
        
        subans.pop_back();
    }
    
};