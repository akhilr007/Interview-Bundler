class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){

        if(head == NULL) return NULL;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* right = head;
        while(n>0 && right != NULL){
            right = right->next;
            n--;
        }

        ListNode* left = dummy;
        while(right != NULL){
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dh->next;   
    }
};