class Solution {
public:
    // time complexity -> O((log n) ^ 2)

    int findLeftHeight(TreeNode* root){

        int height = 0;
        while(root){
            root = root->left;
            height++;
        }

        return height;
    }

    int findRightHeight(TreeNode* root){

        int height = 0;
        while(root){
            root = root->right;
            height++;
        }

        return height;
    }

    int countNodes(TreeNode* root){

        if(root == NULL)
            return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};