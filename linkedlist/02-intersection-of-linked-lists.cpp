class Solution{
private:
    int findLength(ListNode* head){
        int len=0;
        while(head != NULL){
            len++;
            head = head->next;
        }

        return len;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){

        if(headA == NULL || headB == NULL) return NULL;

        int lengthA = findLength(headA);
        int lengthB = findLength(headB);

        ListNode* curNode1 = headA, *curNode2 = headB;

        if(lengthA > lengthB){
            int diff = lengthA - lengthB;
            while(diff > 0){
                curNode1 = curNode1->next;
                diff--;
            }
        }
        else{
            int diff = lengthB-lengthA;
            while(diff > 0){
                curNode2 = curNode2->next;
                diff--;
            }
        }

        while(curNode1 != NULL && curNode2 != NULL){
            if(curNode1 == curNode2) return curNode1;

            curNode1 = curNode1->next;
            curNode2 = curNode2->next;
        }

        return NULL;
    }
};