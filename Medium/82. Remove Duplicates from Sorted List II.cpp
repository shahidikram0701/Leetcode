// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, bool> filter;
        
        ListNode* current = head;
        
        while(current != NULL) {
            if(filter.find(current->val) == filter.end()) {
                filter[current->val] = false;
                if(current->next != NULL and current->val == current->next->val) {
                    filter[current->val] = true;
                } 
            }
            current = current->next;
        }
        
        // for(auto p: filter) {
        //     cout << p.first << " => " << p.second << endl;
        // }
        
        ListNode* newHead = NULL;
        ListNode* newCurrent = NULL;
        
        current = head;
        
        while(current != NULL) {
            if(!filter[current->val]) {
                ListNode* newNode = new ListNode(current->val);
                if(newHead == NULL) {
                    newHead = newCurrent = newNode;   
                }
                else {
                    newCurrent->next = newNode;
                    newCurrent = newNode;
                }
            }
            current = current->next;
        }
        return newHead;
    }
};