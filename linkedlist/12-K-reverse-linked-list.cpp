class Solution{
public:
    int findLength(ListNode* head){

        int len=0;
        while(head){
            len++;
            head = head->next;
        }

        return len;
    }

    void addFirst(ListNode* node, ListNode* &tempHead, ListNode* &tempTail){

        if(tempHead == NULL){
            tempHead = node;
            tempTail = node;
        }
        else{
            node->next = tempHead;
            tempHead = node;
        }
    }

    ListNode* KReverseList(ListNode* head, int k){

        if(head == NULL || head->next == NULL || k == 1) return head;

        int length = findLength(head);

        ListNode* cur = head;
        ListNode* originalHead = NULL, *originalTail = NULL;
        ListNode* tempHead = NULL, *tempTail = NULL;

        while(length >= k){
            int tempK = k;

            while(tempK-- > 0){

                ListNode* nxt = cur->next;
                cur->next = NULL;

                addFirst(cur, tempHead, tempTail);
                cur = nxt;
            }

            if(originalHead == NULL){
                originalHead = tempHead;
                originalTail = tempTail;
            }
            else{
                originalTail->next = tempHead;
                originalTail= tempTail;
            }

            tempHead=NULL;
            tempTail=NULL;
            length -= k;
        }

        originalTail->next = cur;
        return originalHead;

    }
};