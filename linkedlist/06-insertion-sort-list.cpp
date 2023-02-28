class Solution{
public:
    ListNode* insertionSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = head, *cur = head->next;
        while(cur != NULL){
            
            if(cur->val >= prev->val){
                prev = cur;
                cur = cur->next;
                continue;
            }

            ListNode* temp = dummy;
            while(cur->val > temp->next->val){
                temp = temp->next;
            }

            prev->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            cur = prev->next;
        }

        return dummy->next;
    }
};