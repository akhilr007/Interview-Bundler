ListNode* Solution::reverseList(ListNode* head) {

    ListNode* curr = head;
    ListNode* prev = NULL, *nxt = NULL;

    while(curr != NULL){

        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }

    return prev;
}