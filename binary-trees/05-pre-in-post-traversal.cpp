class Solution{
public: 
    void preInPost(TreeNode* root){

        vector<int> pre, post, in;

        stack< pair<TreeNode*, int> > st;
        st.push( {root, 1} );

        while(!st.empty()){

            auto node = st.top();
            st.pop();

            if(node.second == 1){
                pre.push_back(node.first->data);
                node.second++;

                st.push(node);

                if(node.first->left != NULL){
                    st.push( {node.first->left, 1} );
                }
            }

            else if(node.second == 2){

                in.push_back(node.first->data);
                node.second++;

                st.push(node);

                if(node.first->right != NULL){
                    st.push({node.first->right, 1});
                }
            }

            else{
                post.push_back(node.first->data);
            }
        }

    } 
};