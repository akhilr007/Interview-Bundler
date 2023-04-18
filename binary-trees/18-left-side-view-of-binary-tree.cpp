class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res, int level){

        if(root == NULL)
            return;

        if(level == res.size()){
            res.push_back(root->val);
        }

        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);

    }
    
    vector<int> leftSideView(TreeNode* root){

        vector<int> res;

        if(root == NULL)
            return res;

        dfs(root, res, 0);
        return res;
    }
};