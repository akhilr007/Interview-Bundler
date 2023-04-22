class Solution {
public:
    int findInorderSuccessor(TreeNode* root){

        int data = root->val;
        while(root->left != NULL){
            data = root->left->val;
            root = root->left;
        }

        return data;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key){

        if(root == NULL)
            return NULL;

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left == NULL)
                return root->right;
            else if(root->right == NULL)
                return root->left;

            int newData = findInorderSuccessor(root->right);
            root->val = newData;

            root->right = deleteNode(root->right, newData);
        }

        return root;
    }
};