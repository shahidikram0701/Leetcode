// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));

        vector<int> ans;

        int currentLevel = 0;
        int prev = root->val;
        while(!q.empty()) {
            int level = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();

            if(level > currentLevel) {
                ans.push_back(prev);
                currentLevel = level;
            }

            if(node->left != NULL) {
                q.push(make_pair(level+1, node->left));
            }

            if(node->right != NULL) {
                q.push(make_pair(level+1, node->right));
            }

            prev = node->val;
        }
        ans.push_back(prev);
        return ans;
    }
};