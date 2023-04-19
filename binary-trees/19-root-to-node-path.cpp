class Solution {
public:
    // time complexity -> O(n)
    // space complexity -> O(n)
    bool getPath(TreeNode* root, int target, vector<int>& result){

        if(root == NULL)
            return false;

        result.push_back(root->val);

        if(root->val == target)
            return true;

        bool left = getPath(root->left, target, result);
        if(left == true)
            return true;

        bool right = getPath(root->right, target, result);
        if(right == true)
            return true;

        // agar na left se mila na right se then jo element ko push kiya use pop out kar do
        result.pop_back();
        return false;
    }

    vector<int> rootToNodePath(TreeNode* root, int target){

        vector<int> result;

        getPath(root, target, result);

        return result;
    }
};