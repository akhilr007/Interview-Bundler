class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result){

        if(root == NULL)
            return;

        inorder(root->left, result);

        result.push_back(root->data);

        inorder(root->right, result);
        
    }

    vector<int> inorderIterative(TreeNode* root){

        vector<int> result;

        if(root == NULL)
            return result;

        stack<TreeNode*> st;
        st.push(root);

        TreeNode* cur = root;

        while(true){

            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                if(st.empty()) break;

                cur = st.top();
                st.pop();

                result.push_back(cur->data);

                if(cur->right)
                    cur = cur->right;
            }
        }
    }

    vector<int> inorder(TreeNode* root){
        vector<int> result;

        inorder(root, result);

        return result;
    }
}