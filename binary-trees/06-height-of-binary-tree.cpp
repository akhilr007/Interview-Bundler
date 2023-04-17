class Solution {
public: 
    // time complexity -> O(n)
    // space complexity -> O(height)
    int maxDepth(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
};