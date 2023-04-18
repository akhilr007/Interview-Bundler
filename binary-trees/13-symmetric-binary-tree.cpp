class Solution {
public:
    bool isSymmetric(TreeNode* p, TreeNode* q){

        if(p == NULL and q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;

        bool left = isSymmetric(p->left, q->right);
        bool right = isSymmetric(p->right, q->left);
        bool data = p->val == q->val;

        return left && right && data;
    }

    bool isSymmetric(TreeNode* root){

        return isSymmetric(root, root);
    }
};