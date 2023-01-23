// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = recur(nums, 0, nums.size() - 1);

        return root;
    }
    
    TreeNode* recur(vector<int>& nums, int l, int r) {
        if(l == r) {
            return new TreeNode(nums[l]);
        }
        if(l > r) {
            return NULL;
        }
        int index_max = max_element(nums.begin() + l, nums.begin() + (r + 1)) - nums.begin();
        TreeNode *root = new TreeNode(nums[index_max]);
        root->left = recur(nums, l, index_max - 1);
        root->right = recur(nums, index_max + 1, r);
        
        return root;
    }
};