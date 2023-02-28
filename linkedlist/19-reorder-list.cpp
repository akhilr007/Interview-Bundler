class Solution{
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){

        ListNode* prev = NULL, *cur = head;
        while(cur != NULL){
            ListNode* nxt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    ListNode* reorderList(ListNode* head){

        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* t2 = mid->next;
        mid->next = NULL;

        ListNode* t1 = head;
        t2 = reverseList(t2);

        ListNode* dummy = new ListNode(-1);
        ListNode* dt = dummy;

        bool flag = false;
        while(t1 != NULL && t2 != NULL){
            if(!flag){
                dt->next = t1;
                t1 = t1->next;
            }
            else{
                dt->next = t2;
                t2 = t2->next;
            }

            flag = !flag;
            dt = dt->next;
        }

        if(t1) dt->next = t1;
        if(t2) dt->next = t2;

        return dummy->next;
    }
};