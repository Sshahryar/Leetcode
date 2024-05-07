class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {

        ListNode* reversedHead = reverseList(head);
        ListNode* current = reversedHead;
        int maxValue = INT_MIN;
        ListNode* prev = nullptr;

        while (current != nullptr) {
            if (current -> val < maxValue) {
                prev -> next = current -> next;
            } else {
                maxValue = current -> val;
                prev = current;
            }
            current = current -> next;
        }
        return reverseList(reversedHead);
    }
};
