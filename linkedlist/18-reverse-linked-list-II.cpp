class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right){

        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* leftPrev = dummy, *cur = head;
        for(int i=0; i<left-1; i++){
            leftPrev = cur;
            cur = cur->next;
        }

        ListNode* prev = NULL;
        for(int i=0; i<right-left+1; i++){
            ListNode* nxt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        leftPrev->next->next = cur;
        leftPrev->next = prev;

        return dummy->next;
    }
};