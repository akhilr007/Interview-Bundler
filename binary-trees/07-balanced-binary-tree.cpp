/*
brute force:
1. for each node check if the left and right nodes are balanced.
2. for each node check if the left and right subtree are balanced
*/

// time complexity -> O(n2)
// space complexity -> O(n)
class Solution {
public:
    int findHeight(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->left);

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;

        bool leftIsBalanced = isBalanced(root->left);
        bool rightIsBalanced = isBalanced(root->right);

        bool absDiff = abs(findHeight(root->left) - findHeight(root->right)) <= 1;

        return leftIsBalanced && rightIsBalanced && absDiff;
    }
};


// optimal
// time complexity -> O(n)
// space complexity -> O(height of tree)
class Solution {
public:
    int dfsHeight(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftHeight = dfsHeight(root->left);

        if(leftHeight == -1)
            return -1;

        int rightHeight = dfsHeight(root->right);

        if(rightHeight == -1)
            return -1;

        if(abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root){
        return dfsHeight(root) != -1;
    }
};