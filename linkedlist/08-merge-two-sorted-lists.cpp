class Solution{
public:
    ListNode* mergeLists(ListNode* head1, ListNode* head2){

        if(head1 == NULL || head2 == NULL){
            return head1 != NULL ? head1 : head2;
        }

        ListNode* l1 = head1;
        ListNode* l2 = head2;

        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;

        while(l1 != NULL && l2 != NULL){

            if(l1->val < l2->val){
                dt->next = l1;
                l1 = l1->next;
            }
            else{
                dt->next = l2;
                l2 = l2->next;
            }
            dt = dt->next;
        }

        if(l1 != NULL) dt->next = l1;
        if(l2 != NULL) dt->next = l2;

        return dh->next;
    }
};