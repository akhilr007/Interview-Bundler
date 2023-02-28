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

    void addLast(ListNode* node, ListNode* &tempHead, ListNode* &tempTail){

        if(tempHead == NULL){
            tempHead = node;
            tempTail = node;
        }
        else{
            tempTail->next = node;
            tempTail = node;
        }
    }

    ListNode* reverseAlternateKNodes(ListNode* head, int k){

        if(head == NULL || head->next == NULL || k == 0 || k==1) return head;

        int length = findLength(head);

        ListNode* originalHead = NULL, *originalTail = NULL;
        ListNode* tempHead = NULL, *tempTail = NULL;

        ListNode* cur = head;
        bool toReverse=true;

        while(length >= k){

            int tempK = k;

            while(tempK-- > 0){
                if(toReverse == true){

                    ListNode* nxt = cur->next;
                    cur->next = NULL;

                    addFirst(cur, tempHead, tempTail);
                    cur = nxt;
                }
                else{
                    ListNode* nxt = cur->next;
                    cur->next = NULL;

                    addLast(cur, tempHead, tempTail);
                    cur = nxt;
                }
            }

            if(originalHead == NULL){
                originalHead = tempHead;
                originalTail = tempTail;
            }
            else{
                originalTail->next = tempHead;
                originalTail = tempTail;
            }

            tempHead = tempTail = NULL;
            flag = !flag;
            length -= k;
        }

        originalTail->next = cur;
        return originalHead;
    }
};