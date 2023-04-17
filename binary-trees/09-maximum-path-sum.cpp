class Solution{
public:
// time complexity -> O(n)
// space complexity -> O(height of tree)
    int dfs(TreeNode* root, int& max_sum){

        if(root == NULL)
            return 0;

        int left = dfs(root->left, max_sum);
        int right = dfs(root->right, max_sum);

        // subtree path with left and right answer h neeche hi ans mil gaya
        int subtree_with_left_and_right = left + right + root->val;

        // subtree path with left or right ans h left ya right se koi ek lena h kyuki koi -ve b ho sakta h
        int subtree_with_left_or_right = root->val + max(left, right);

        // left and right dono -ve h, isliye sirf root hi lena hai
        int only_root = root->val;
        
        max_sum = max({ max_sum, subtree_with_left_and_right, subtree_with_left_or_right, only_root});

        // return hum sirf root ya subtree with left or right kar sakte h kyuki left and right apne me ek
        // path bana raha h
        return max(only_root, subtree_with_left_or_right);
    }

    int maxPathSum(TreeNode* root){

        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
};