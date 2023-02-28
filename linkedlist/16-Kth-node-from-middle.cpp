class Solution{
public:
    ListNode* findMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        // for even choose the 2nd node
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    int kthNodeFromMiddle(ListNode* head, int k){

        if(head == NULL) return -1;

        ListNode* mid = findMid(head);
        mid->next = NULL;

        ListNode* slow = head, *fast = head;
        while(k-->0 && fast != NULL) fast = fast->next;

        if(fast == NULL) return -1;

        ListNode* slowPrev = NULL;
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        return slowPrev != NULL ? slowPrev->val : -1;
    }
};