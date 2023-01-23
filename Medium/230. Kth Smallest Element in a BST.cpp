// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        int k_smallest = -1;
        int count = 0;
        recur(root, k, k_smallest, count);
        return k_smallest;
    }
    
    void recur(TreeNode* root, int k, int& k_smallest, int& count) {
        if(root != NULL) {
            recur(root->left, k, k_smallest, count);
            count++;
            if(count == k) {
                k_smallest = root->val;
            }
            recur(root->right, k, k_smallest, count);
        }
    }
};