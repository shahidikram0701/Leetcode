// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        int count = 0;
        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* prev = NULL;
        ListNode* startingEven = second;
        
        while(second != NULL) {
            first->next = second->next;
            prev = first;
            first = second;
            second = second->next;
            count++;
        }
        if(count % 2 != 0) {
            prev->next = startingEven;
        }
        else {
            first->next = startingEven;
        }
        
        return head;
    }
};