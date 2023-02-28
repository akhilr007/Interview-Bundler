class Solution{
public:
    int findLength(ListNode* node){
        int len=0;

        while(node != NULL){
            len++;
            node = node->next;
        }
        return len;
    }

    ListNode* rotateList(ListNode* head, int k){

        if(head == NULL || head->next == NULL || k == 0) return head;

        int length = findLength(head);
        k = k % length;

        if(k == 0) return head;

        ListNode* slowPrev = NULL;
        ListNode* slow = head, *fast = head;

        while(k-->0 && fast != NULL){
            fast = fast->next;
        }

        while(fast != NULL){
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        slowPrev->next = NULL;

        ListNode* slowTail = slow;
        while(slowTail->next != NULL) slowTail = slowTail->next;

        slowTail->next = head;
        return slow;
    }
}