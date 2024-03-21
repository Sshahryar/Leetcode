class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode *temp1 = list2, *head = list1, *pos = list2, *end = list1;

        while(list2 -> next){
            list2 = list2 -> next;
        }
        int i = 0, j = 0;

        while(list1 || i == a && j == b){
            if(i == a - 1){
                pos = list1;
        }
        if(j == b){
            end = list1;
        }
        i++;
        j++;
        list1 = list1 -> next;
        }
        pos -> next = temp1;
        list2 -> next = end -> next;

        return head;
    }
};
