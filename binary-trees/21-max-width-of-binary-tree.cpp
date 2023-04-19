class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){

        if(root == NULL)
            return 0;

        queue< pair<TreeNode*, int> > q;
        q.push( {root, 0} ); // { root, index }

        int maxWidth = 0;

        while(!q.empty()){

            int size = q.size();
            int first, last;

            for(int i=0; i<size; i++){

                long current_index = q.front().second;
                auto node = q.front().first;
                q.pop();

                if(i == 0)
                    first = current_index;
                if(i == size-1)
                    last = current_index;

                if(node->left)
                    q.push( {node->left, current_index * 2 + 1 });
                if(node->right)
                    q.push( {node->right, current_index * 2 + 2} );
            }

            maxWidth = max(maxWidth, (last - first) + 1);
        }

        return maxWidth;
    }
};