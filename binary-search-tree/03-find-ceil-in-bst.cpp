class Solution {
public:
    // time complexity -> O(log n)
    // space complexity -> O(1)
    int findCeil(TreeNode* root, int input){

        int ceilOfInput = -1;
        while(root != NULL){

            if(root->val == input){
                return input;
            }

            if(input < root->val){
                /*
                    if root's value is > than input then it can be ceil of input,
                    so we store the root's value as our answer and to minimize the 
                    answer we go to left of root 
                */
                ceilOfInput = input;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }

        return ceilOfInput;
    }
};