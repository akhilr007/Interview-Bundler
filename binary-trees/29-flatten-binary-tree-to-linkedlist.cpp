class Solution {
public:
    void helper(TreeNode* root, TreeNode* &prev){

        if(root == NULL)
            return;

        helper(root->right, prev);
        helper(root->left, prev);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }

    void flatten(TreeNode* root){

        if(root == NULL)
            return;

        TreeNode* prev = NULL;
        helper(root, prev);
    }
};