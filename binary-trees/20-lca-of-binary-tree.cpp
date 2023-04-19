class Solution {
public:
    // time complexity -> O(2n for traversal) + O(min(n, m))
    // space complexity -> O(2 height of tree)
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& result){

        if(root == NULL)
            return false;

        result.push_back(root);

        bool left = getPath(root->left, target, result);
        if(left == true) return true;

        bool right = getPath(root->right, target, result);
        if(right == true) return true;

        result.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> rootToNodeP, rootToNodeQ;

        getPath(root, p, rootToNodeP);
        getPath(root, q, rootToNodeQ);

        int n = rootToNodeP.size() , m = rootToNodeQ.size();

        int i;
        for(i=0; i<n && i<m; i++){
            if(rootToNodeP[i] != rootToNodeQ[i])
                break;
        }

        return rootToNodeP[i-1];
    }
};

// optimal
class Solution{
public:
    // time complexity -> O(n)
    // space complexity -> O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
    }
};