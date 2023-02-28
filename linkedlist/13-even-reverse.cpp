class Solution{
public:
    ListNode* reverseList(ListNode* head){

        ListNode* cur = head;
        ListNode* prev = NULL, *nxt = NULL;

        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        return prev;
    }
    
    ListNode* evenReverse(ListNode* head){

        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;

        // 1. segregate odd and even nodes
        ListNode* dummyOdd = new ListNode(-1);
        ListNode* dummyOddTail = dummyOdd;

        ListNode* dummyEven = new ListNode(-1);
        ListNode* dummyEvenTail = dummyEven;

        ListNode* cur = head;
        bool flag = false;

        while(cur != NULL){

            if(flag == false){
                dummyOddTail->next = cur;
                dummyOddTail = dummyOddTail->next;
            }
            else{
                dummyEvenTail->next = cur;
                dummyEvenTail = dummyEvenTail->next;
            }

            cur = cur->next;
            flag = !flag;
        }

        dummyOddTail->next = NULL;
        dummyEvenTail->next = NULL;
        // 2. reverse even nodes
        ListNode* odd = dummyOdd->next;
        ListNode* even = reverseList(dummyEven->next);

        // 3. concatenate odd and even nodes
        ListNode* dummy = new ListNode(-1);
        ListNode* dt = dummy;
        flag = false;
        while(odd != NULL && even != NULL){

            if(flag == false) {
                // odd
                dt->next = odd;
                odd = odd->next;
            }
            else{
                dt->next = even;
                even = even->next;
            }
            dt = dt->next;
            flag = !flag;
        }

        if(odd) dt->next = odd;
        if(even) dt->next = even;

        return dummy->next;

    }
};