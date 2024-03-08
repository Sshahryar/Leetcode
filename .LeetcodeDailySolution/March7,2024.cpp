class Solution {
public:
ListNode* middleNode(ListNode* head) {

    ListNode *fast=head, *slow=head;

    while(fast->next&& fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
   return (fast->next) ? slow->next:slow;
  }
};
