class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res, int level){

        if(root == NULL)
            return;

        if(level == res.size()){
            res.push_back(root->data);
        }

        dfs(root->right, res, level + 1);
        dfs(root->left, res, level + 1);

    }

    vector<int> rightSideView(TreeNode* root){

        vector<int> res;

        if(root == NULL)
            return res;

        dfs(root, res, 0);
        return res;
    }
};