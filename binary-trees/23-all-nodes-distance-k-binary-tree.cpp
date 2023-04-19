class Solution{
public:
    void markParentNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &nodeToParent){

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            for(int i=0; i<size; i++){

                auto node = q.front();
                q.pop();

                if(node->left){
                    nodeToParent[node->left] = node;
                    q.push(node->left);
                }

                if(node->right){
                    nodeToParent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){

        vector<int> result;
        if(root == NULL)
            return result;

        unordered_map< TreeNode*, TreeNode* > nodeToParent;
        markParentNode(root, nodeToParent);

        queue < TreeNode* > q;
        q.push(target);

        unordered_map< TreeNode*, bool > visited;
        visited[target] = true;

        int level = 0;

        while(!q.empty()){

            int size = q.size();
            if(level == k) break;

            for(int i=0; i<size; i++){

                auto node = q.front();
                q.pop();

                if(node->left && visited[node->left] == false){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && visited[node->right] == false){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parent[node] && nodeToParent[parent[node]] == false){
                    q.push(nodeToParent[node]);
                    visited[nodeToParent[node]] = true;
                }
            }

            level ++;
        }

        while(!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};