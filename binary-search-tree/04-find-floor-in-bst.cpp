class Solution {
public:
    // time complexity -> O(log n)
    // space complexity -> O(1)
    int findFloor(TreeNode* root, int input){

        int floorOfInput = -1;
        while(root != NULL){

            if(root->val == input){
                return input;
            }

            if(input < root->val){
                root = root->left;
            }
            else{
                floorOfInput = root->val;
                root = root->right;
            }
        }

        return floorOfInput;
    }
};