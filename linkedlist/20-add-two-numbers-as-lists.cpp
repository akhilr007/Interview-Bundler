class Solution{
public:
    ListNode* addNumbers(ListNode* l1, ListNode* l2){

        if(l1 != NULL || l2 != NULL){
            return l1 != NULL ? l1 : l2;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* dt = dummy;

        int carry = 0;

        while(l1 != NULL || l2 != NULL){

            int v1=0, v2=0;
            if(l1) v1 = l1->val;
            if(l2) v2 = l2->val;

            int sum = v1 + v2 + carry;
            ListNode* nn = new ListNode(sum % 10);
            carry = sum / 10;

            dt->next = nn;
            dt = dt->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry){
            ListNode* nn = new ListNode(1);
            dt->next = nn;
            dt = dt->next;
        }
        return dummy->next;
    }
};