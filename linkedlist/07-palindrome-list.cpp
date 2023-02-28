class Solution{
public:
    ListNode* findMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){

        ListNode* prev = NULL, *nxt = NULL;
        ListNode* cur = head;

        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head){

        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* R = mid->next;
        mid->next = NULL;

        ListNode* L = head;
        R = reverseList(R);

        while(L != NULL && R != NULL){
            if(L->val != R->val) return false;

            L = L->next;
            R = R->next;
        }

        return true;
    }
};