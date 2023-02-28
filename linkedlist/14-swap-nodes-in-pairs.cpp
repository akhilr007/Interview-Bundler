class Solution{
public:
    ListNode* swapNodesPairs(ListNode* head){

        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        while(prev->next != NULL && prev->next->next != NULL){

            ListNode* cur = prev->next;
            ListNode* curNxt = cur->next;
            ListNode* temp = curNxt->next;

            prev->next = curNxt;
            curNxt->next = cur;
            cur->next = temp;

            prev = cur;
        }

        return dummy->next;
    }
};