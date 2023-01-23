// https://leetcode.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) {
            return;
        }
        
        vector<ListNode*> nodes;
        int n = 0;
        
        ListNode *current = head;
        
        while(current != NULL) {
            nodes.emplace_back(current);
            ++n;
            current = current->next;
        }
        
        for(int i = 0; i < n / 2; ++i) {
            int i_to_swap = n - i - 1;
            
            nodes[i]->next = nodes[i_to_swap];
            nodes[i_to_swap]->next = nodes[i+1];
        }
        nodes[n/2]->next = NULL;

        
    }
};