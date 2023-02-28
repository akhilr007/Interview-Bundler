class Solution{
private:
    ListNode* findMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    ListNode* mergeList(ListNode* l1, ListNode* l2){

        if(l1 == NULL || l2 == NULL){
            return l1 != NULL ? l1 : l2;
        }

        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                dt->next = l1;
                l1 = l1->next;
            }
            else{
                dt->next = l2;
                l2 = l2->next;
            }
            dt = dt->next;
        }

        if(l1 != NULL) dt->next = l1;
        if(l2 != NULL) dt->next = l2;

        return dh->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* secondList = mid->next;
        mid->next = NULL;

        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(secondList);

        return mergeList(l1, l2);
    }

    ListNode* sortList(ListNode* head){
        return mergeSort(head);
    }
};