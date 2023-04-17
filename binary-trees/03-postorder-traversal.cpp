class Solution {
public:

    void postorder(TreeNode* root, vector<int>& result){

        if(root == NULL){
            return;
        }

        postorder(root->left, result);
        postorder(root->right, result);

        result.push_back(root->data);

    }

    vector<int> postorderIterative(TreeNode* root){

        vector<int> result;

        if(root == NULL)
            return result;

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* curr = root;

        s1.push(cur);

        while(!s1.empty()){

            cur = s1.top();
            s1.pop();

            s2.push(cur);
            
            if(cur->left)
                s1.push(cur->left);
            if(cur->right)
                s2.push(cur->right);
        }

        while(!s2.empty()){
            result.push_back(s2.top());
            s2.pop();
        }

        return result;
    }

    vector<int> postorder(TreeNode* root){

        vector<int> result;

        postorder(root, result);
        return result;
    }
};