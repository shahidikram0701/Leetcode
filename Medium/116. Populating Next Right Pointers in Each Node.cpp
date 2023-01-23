// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return NULL;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            Node* prev = NULL;
            for(int i = 0; i < s; ++i) {
                Node* cur = q.front();
                if(prev != NULL) {
                    prev -> next = cur;
                }
                prev = cur;
                q.pop();
                if(cur -> left != NULL)
                    q.push(cur->left);
                if(cur -> right != NULL)
                    q.push(cur->right);
            }
        }

        return root;
    }
};