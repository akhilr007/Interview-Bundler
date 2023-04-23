/*
    brute:
    1. store all the nodes in array using any tree traversal.
    2. sort the array therefore it will be traversal of inorder in bst.
    3. do inorder traversal and put all the node values using array values
*/

class Solution {
private:
    TreeNode* first, *last, *middle, *prev;
public:
    void inorder(TreeNode* root){

        if(root == NULL)
            return;

        inorder(root->left);

        if(prev != NULL && (prev->val > root->val)){

            // first violation
            if(first == NULL){
                // mark both nodes
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }

        prev = root;
        inorder(root->left);
    }

    void recoverBST(TreeNode* root){

        first = last = middle = prev = NULL;

        inorder(root);

        if(first && last)
            swap(first->val, last->val);
        else    
            swap(first->val, middle->val);
    }
};