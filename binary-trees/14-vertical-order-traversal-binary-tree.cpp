class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL) return res;

        // har horizontal distance pe levels ho sakte h and har levels pe nodes
        map < int, map <int, multiset<int> > > mpp;

        queue < pair<TreeNode*, pair<int, int> > > q;
        // { node , {horizontal_distance, level }}

        q.push({root, {0, 0} });

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int horizontal_distance = it.second.first;
            int level = it.second.second;

            mp[horizontal_distance][level].insert(node->val);

            if(node->left)
                q.push( {node->left, {horizontal_distance - 1, level + 1} } );

            if(node->right)
                q.push( {node->right, {horizontal_distance + 1, level + 1} } );
        }


        for(auto p : mpp){

            vector<int> cols;
            for(auto q : p.second){

                multiset<int> nodes = q.second;

                for(auto r: nodes){

                    cols.push_back(r);
                }
            }

            res.push_back(cols);
        }

        return res;
    }
};