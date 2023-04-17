class Solution{
public:
    vector<int> levelOrder(TreeNode* root){

        vector<int> result;
        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            result.push_back(node->data);

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        return result;
    }
};