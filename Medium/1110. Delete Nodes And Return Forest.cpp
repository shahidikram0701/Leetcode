// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> to_delete_set(to_delete.begin(), to_delete.end());
        bool root_delete = recur(root, to_delete_set, ans);
        if(!root_delete) {
            ans.emplace_back(root);
        }
        return ans;
    }
    
    bool recur(TreeNode* root, set<int>& to_delete,  vector<TreeNode*>& ans) {
         if(root == NULL) {
             return false;
        }
        
        int leftDelete = recur(root->left, to_delete, ans);
        int rightDelete = recur(root->right, to_delete, ans);
        bool delete_this_node = to_delete.find(root->val) != to_delete.end();
        if(delete_this_node) {
            if(root->left != NULL and !leftDelete) {
                ans.emplace_back(root->left);
            }
            if(root->right != NULL and !rightDelete) {
                ans.emplace_back(root->right);
            }
        }
        if(leftDelete) {
            root->left = NULL;
        }
        if(rightDelete) {
            root->right = NULL;
        }
        return delete_this_node;
    }
};