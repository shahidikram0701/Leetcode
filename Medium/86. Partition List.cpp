// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = NULL;
        ListNode* right = NULL;
        ListNode* rightBeg = NULL;

        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* pprev = NULL;

        while(true) {
            if(prev != NULL) {
                if(prev -> val < x) {
                    if(pprev != NULL) {
                        pprev -> next = prev -> next;
                    }
                    prev -> next = rightBeg;
                    if(left == NULL) {
                        left = prev;
                        head = left;
                    } else {
                        left -> next = prev;
                        left = prev;
                    }
                    
                    prev = pprev;
                } else {
                    if(rightBeg == NULL) {
                        rightBeg = right = prev;
                        if(left != NULL)
                            left -> next = rightBeg;
                    } else {
                        right -> next = prev;
                        prev -> next = NULL;
                        right = prev;
                    }
                    
                }
            }
            pprev = prev;
            prev = current;
            if(current != NULL)
                current = current -> next;

            if(prev == NULL) {
                break;
            }
        }
        return head;
    }
};