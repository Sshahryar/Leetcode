class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        int carry = twice(head);

        if (carry > 0) {
            head = new ListNode(carry, head);
        }
        return head;
    }
private:
    int twice(ListNode* head) {

        if (head == nullptr) {
            return 0;
        }
 
        int doubledValue = head -> val * 2 + twice(head -> next);
        head -> val = doubledValue % 10;
        
        return doubledValue / 10;
    }
};
