// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
public:
    bool recur(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode **ans) {
        if(root == NULL) {
            return false;
        }
        
        bool isCurrentNode = (root == p) || (root == q);
        bool left = recur(root->left, p, q, ans);
        bool right = recur(root->right, p, q, ans);
        
        bool condition = (left && right) || (left && isCurrentNode) || (right && isCurrentNode);
        
        // cout << root->val << " -- condition -- " << condition;
        // cout << " -- left --" << left << " -- right -- " << right;
        // cout << " -- isCurrentNode -- " << isCurrentNode << endl;
        if(condition) {
            *ans = root;
        }
        return left || right || isCurrentNode;
    }
    
};