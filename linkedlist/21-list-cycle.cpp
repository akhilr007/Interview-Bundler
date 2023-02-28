class Solution{
public:
    ListNode* listCycle(ListNode* head){

        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        if(slow != fast) return NULL;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};