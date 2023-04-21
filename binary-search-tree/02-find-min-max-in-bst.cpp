class Solution {
public:
    vector<int> findMinMax(TreeNode* root){

        int min_value = INT_MAX, max_value = INT_MIN;
        
        TreeNode* currNode = root;
        while(root != NULL){
            min_value = min(min_value, currNode->val);
            currNode = currNode->left;
        }

        currNode = root;
        while(root != NULL){
            max_value = max(max_value, currNode->val);
            currNode = currNode->right;
        }

        vector<int> res(2); // 0 -> min_value, 1 -> max_value
        res[0] = min_value == INT_MAX ? -1 : min_value;
        res[1] = max_value == INT_MIN ? -1 : max_value;

        return res;
    }
}