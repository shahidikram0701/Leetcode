// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> nextMap;
        Node* copy = new Node(head->val);
        nextMap[head] = head->next;
        Node* current = head->next;
        Node* previous = head;
        Node* currentNew = copy;
        Node* previousNew = NULL;
        while(current != NULL) {
            nextMap[current] = current->next;
            Node* node = new Node(current->val);
            currentNew->next = node;
            previous->next = currentNew;
            currentNew->random = previous;
            
            previous = current;
            current = current->next;
            currentNew = node;
        }
        previous->next = currentNew;
        currentNew->random = previous;
        
        
        currentNew = copy;
        while(currentNew != NULL) {
            // cout << currentNew->val << endl;
            if(currentNew->random->random == NULL) {
                currentNew->random = NULL;
            } else {
                currentNew->random = currentNew->random->random->next;
                // cout << "radom: " << currentNew->random->val << endl;
            }
            currentNew = currentNew->next;
        }
        for(auto p: nextMap) {
            p.first->next = p.second;
        }
        
        return copy;
    }
};