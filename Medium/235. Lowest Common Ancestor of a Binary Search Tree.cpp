// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        
        recur(root, p, q, &ans);
        
        return ans;
    }
    
    bool recur(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** ans) {
        if(root == NULL) {
            return false;
        }
        
        bool is_p = (root == p);
        bool is_q = (root == q);
        
        int l = recur(root->left, p, q, ans);
        int r = recur(root->right, p, q, ans);
        
        if((l and r) or (is_p and r) or (is_q and l) or (is_p and l) or (is_q and r)) {
            *ans = root;
        }   
        return is_p or is_q or l or r;
    }  
};