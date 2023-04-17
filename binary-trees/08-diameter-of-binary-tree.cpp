// brute force
// time complexity -> O(n2)
// space complexity -> O(height of tree)
class Solution {
public:
    int height(TreeNode* root){

        if(root == NULL)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int diameterWithRoot = leftHeight + rightHeight + 2;
        // 2 -> edges connected with root

        return max({leftDiameter, rightDiameter, diameterWithRoot}); 
    }
};

// optimal solution 
// time complexity -> O(n)
// space complexity -> O(height of tree)

class Solution{
public:
    int height(TreeNode* root, int& diameter){

        if(root == NULL)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight + 2);

        return max(leftHeight, rightHeight) + 1;

    }
    
    int diameterOfBinaryTree(TreeNode* root){

        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
}