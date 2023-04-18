class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector <int> > res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        
        while(!q.empty()){

            int size = q.size();
            vector<int> ans(size);

            for(int i=0; i<size; i++){

                auto node = q.front();
                q.pop();

                if(leftToRight){
                    ans[i] = node->val;
                }
                else{
                    ans[size-i-1] = node->val;
                }

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            leftToRight = !leftToRight;
            res.push_back(ans);
        }

        return res;
    }
};