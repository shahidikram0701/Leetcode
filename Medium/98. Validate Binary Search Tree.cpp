// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        return recur(root, LLONG_MIN, LLONG_MAX);   
    }
    
    bool recur(TreeNode* root, long long min, long long max) {
        if(root == NULL) {
            return true;
        }        
        
        bool left = recur(root->left, min, root->val);
        bool right = recur(root->right, root->val, max);
        
        
        return root->val > min and root->val < max and left and right;
        
    }
};