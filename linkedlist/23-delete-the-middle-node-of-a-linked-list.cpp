class Solution{
public:
    ListNode* deleteMiddle(ListNode* head){

        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* slowBehind = NULL;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slowBehind = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        slowBehind->next = slow->next;
        delete slow;
        return head;

    }
};