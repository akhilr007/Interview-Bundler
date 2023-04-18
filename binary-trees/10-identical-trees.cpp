class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL and q == NULL)
            return true;
        if(p == NULL or q == NULL)
            return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool data = p->val == q->val;

        return left && right && data;
    }
};