// brute force
// time complexity -> O(n2)

/*
1. for each node calculate the sum of left_child and right_child
2. calculate diff, between the sum of child nodes - root node
3. if diff > 0, means root->val is smaller than sum of child nodes so increase root->val by diff value.
4. if diff < 0, means sum of child nodes is less than root->val so we can increase any child with diff
value, but if we increase the child value we must also increase the subtree value because while increasing
it may affect the children sum property of subtree
*/
class Solution {
public:
    void increment(TreeNode* root, int diff){

        if(root->left){

            root->left->data += diff;
            increment(root->left, diff);
        }
        else if(root->right){
            root->right->data += diff;
            increment(root->right, diff);
        }
    }

    void changeTree(TreeNode* root){

        // for root = null and leaf node please return
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;

        int left_data = 0, right_data = 0;

        // iterate over tree by post-order traversal
        changeTree(root->left);
        changeTree(root->right);

        // if my left child exists, put its value to left data
        if(root->left)
            left_data = root->left->data;
        // same for right child
        if(root->right)
            right_data = root->right->data;

        // calculate diff
        int diff = left_data + right_data - root->data;

        // it means root value is less than sum of its child, so increase it by diff
        if(diff > 0)
            root->data += diff;

        // it means root value is greater than sum of its child, so increase any one of the child
        // nodes value by diff, we are incrementing it to left child
        if(diff < 0)
            increment(root, -diff);
    }
};


// optimal solution
// time complexity -> O(n)
/*
1. here, calculate the sum of child nodes
2. if root->val <= child, put root->data = sum  of child
3. else, root->left->data = root->data and root->right->data = root->data;
4. now traverse post order traversal
5. now again calculate the sum left child and right child
6. if it is not a leaf node put the value to root node
*/

class Solution {
public:
    void changeTree(TreeNode* root){

        if(root == NULL)
            return;

        int childSum = 0;

        if(root->left)
            childSum += root->left->data;
        if(root->right)
            childSum += root->right->data;

        if(childSum >= root->data)
            root->data = childSum;
        else{
            if(root->left) 
                root->left->data = root->data;
            if(root->right)
                root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);

        int total_sum = 0;

        if(root->left)
            total_sum += root->left->data;
        if(root->right)
            total_sum += root->right->data;

        if(root->left || root->right)
            root->data = total_sum;
    }
};