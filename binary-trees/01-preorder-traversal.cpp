// recursion based traversal
class Solution {
public:
    // time complexity -> O(n)
    // space complexity -> O(log n) or O(height of tree) or O(n) for skewed tree
    void preorder(TreeNode* root, vector<int>& result){

        if(root == NULL)
            return;

        result.push_back(root->data);
        
        preorder(root->left, result);
        preorder(root->right, result);

    }

    // iterative traversal
    vector<int> preorderIterative(TreeNode* root){

        vector<int> result;
        if(root == NULL)
            return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){

            auto node = st.top();
            st.pop();

            result.push_back(node->data);

            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
        }

        return result;
    }

    vector<int> preorder(TreeNode* root){

        // root left right

        vector<int> result;

        preorder(root, result);

        return result;
    }
};