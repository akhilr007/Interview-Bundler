class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& index, int max_bound){

        if(index >= preorder.size() || preorder[index] > max_bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index ++]);

        root->left = build(preorder, index, root->val);
        root->right = build(preorder, index, max_bound);

        return root;
    }

    TreeNode* buildBST(vector<int>& preorder){

        int index = 0;
        return build(preorder, i, INT_MAX);
    }
};