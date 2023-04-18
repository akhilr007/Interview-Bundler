class Solution {
public:
    void leftBoundary(TreeNode* root, vector<int>& res){

        if(root == NULL)
            return;
        if(root->left == NULL and root->right == NULL)
            return;
        
        res.push_back(root->data);

        if(root->left)
            leftBoundary(root->left, res);
        else
            leftBoundary(root->right, res);
    }

    void leafBoundary(TreeNode* root, vector<int>& res){

        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            res.push_back(root->data);
            return;
        }

        leafBoundary(root->left, res);
        leafBoundary(root->right, res);
    }

    void rightBoundary(TreeNode* root, vector<int>& res){

        if(root == NULL)
            return;

        if(root->left == NULL and root->right == NULL)
            return;

        if(root->right)
            rightBoundary(root->right, res);
        else    
            rightBoundary(root->left, res);

        res.push_back(root->data);
    }

    vector <int> boundary(TreeNode *root){

        vector<int> res;
        if(root == NULL) return res;

        // root node 
        res.push_back(root->data);
        if(root->left == NULL && root->right == NULL)
            return res;

        leftBoundary(root->left, res);

        leafBoundary(root, res);

        rightBoundary(root->right, res);

        return res;
        
    }
};