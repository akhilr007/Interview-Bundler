class Solution {
public:
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, 
    int inStart, int inEnd, unordered_map<int, int>& mpp){

        if(postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[root->val];
        int nums_on_left = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart+nums_on_left-1, inorder, inStart, inRoot-1, mpp);
        root->right = buildTree(postorder, postStart+nums_on_left, postEnd-1, inorder, inRoot+1, inEnd, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){

        int n = inorder.size();

        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[inorder[i]] = i;
        }

        return buildTree(postorder, 0, n-1, inorder, 0, n-1, mpp);
    }
};