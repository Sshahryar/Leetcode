class Solution {
public:

    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode node = ListNode(0, head);

        ListNode* ptr =& node;

        int prefix = 1000000;

        static ListNode* mp[2000001] = {NULL};

        for( ; ptr; ptr = ptr ->  next){

            prefix += (ptr -> val);

            mp[prefix] = ptr;
        }
        prefix = 1000000, ptr =& node;

        for( ; ptr; ptr = ptr -> next){

            prefix += (ptr -> val);

            ptr -> next = mp[prefix] -> next;
        }
        return node.next;
    }
};
