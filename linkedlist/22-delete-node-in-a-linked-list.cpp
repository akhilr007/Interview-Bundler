class Solution{
public:
    void deleteRandomNode(ListNode* node){
        //node -> not a head node
        node->val = node->next->val;
        node->next = node->next->next;
    }
}