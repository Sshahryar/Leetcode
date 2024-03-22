class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;
        
        while (current != nullptr) {
            next = current -> next; 
            current -> next = prev; 
            prev = current;
            current = next;
        }        
        return prev;
    }
};
