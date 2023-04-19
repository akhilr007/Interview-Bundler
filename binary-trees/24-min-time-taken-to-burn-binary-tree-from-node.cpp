class Solution{
public:

    TreeNode* markParent(TreeNode* root, int start, unordered_map< TreeNode*, TreeNode* > &nodeToParent){

        queue < TreeNode* > q;
        q.push(root);

        TreeNode* target = NULL;
        
        while(!q.empty()){

            int size = q.size();
            
            while(size --){

                auto node = q.front();
                q.pop();

                if(node->data == start){
                    target = node;
                }

                if(node->left){
                    q.push(node->left);
                    nodeToParent[node->left] = node;
                }

                if(node->right){
                    q.push(node->right);
                    nodeToParent[node->right] = node;
                }
            }
        }

        return target;
    }

    int minTimeToBurnTree(TreeNode* start, int startNode){

    
        unordered_map< TreeNode*, TreeNode* > nodeToParent;
        TreeNode* targetNode = markParent(root, startNode, nodeToParent);

        queue < TreeNode* > q;
        q.push(targetNode);

        unordered_map< TreeNode*, bool > visited;
        visited[targetNode] = true;

        int time = 0;
        
        while(!q.empty()){

            int size = q.size();
            bool flag = 0;

            while(size --){

                auto node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                    flag = 1;
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                    flag = 1;
                }

                if(nodeToParent[node] && !visited[nodeToParent[node]]){
                    q.push(nodeToParent[node]);
                    visited[nodeToParent[node]] = true;
                    flag = 1;
                }
            }

            if(flag == 1) time++;
        }

        return time;
    }
};