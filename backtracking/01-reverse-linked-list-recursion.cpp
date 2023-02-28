// 1->2->3->4->5

class Solution{
    ListNode* reverseLinkedList(ListNode* head){

        if(head == NULL) return head;

        ListNode* newHead = head;
        if(head->next != NULL){
            newHead = reverseLinkedList(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return newHead;

    }
};