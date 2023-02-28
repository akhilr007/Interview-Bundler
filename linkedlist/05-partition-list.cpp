class Solution{
public:
    ListNode* partitionList(ListNode* head, int x){

        ListNode* dh = new ListNode(-1); // for smaller values
        ListNode* dt = dh;

        ListNode* dh1 = new ListNode(-1); // for greater than or equal values
        ListNode* dt1 = dh1;

        ListNode* curr = head;
        while(curr != NULL){

            if(curr->val < x){

                dt->next = curr;
                dt = dt->next;
            }
            else{

                dt1->next = curr;
                dt1 = dt1->next;
            }
            curr = curr->next;
        }

        dt1->next = NULL;
        dt->next = dh1->next;
        return dh->next;
    }
};