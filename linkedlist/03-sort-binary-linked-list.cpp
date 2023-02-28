class Solution{
public:
    ListNode* sortBinaryList(ListNode* head){

        if(head == NULL) return NULL;

        ListNode* d0 = new ListNode(-1);
        ListNode* dt0 = d0;

        ListNode* d1 = new -ListNode(1);
        ListNode* dt1 = d1;

        ListNode* currNode = head;

        while(currNode != NULL){
            if(currNode->val == 0){
                dt0->next = currNode;
                dt0 = dt0->next;
            }
            else{
                dt1->next = currNode;
                dt1 = dt1->next;
            }
            currNode = currNode->next;
        }

        dt1->next = NULL;
        dt0->next = d1->next;

        return d0->next;

    }
}