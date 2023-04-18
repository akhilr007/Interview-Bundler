class Solution{
public:
    vector<int> bottomView(Node *root){
        
        vector<int> res;
        if(root == NULL)
            return res;

        // kyuki mujhe har horizontal distance pe ek hi node chaiye to fir horizontal dist ko map kardo node se
        
        map < int, int > mpp;

        queue< pair <Node*, int > > q;

        q.push({root, 0});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int horizontal_distance = it.second;

            mpp[horizontal_distance] = node->data;

            if(node->left)
                q.push({node->left, horizontal_distance - 1});
            if(node->right)
                q.push({node->right, horizontal_distance + 1});
        }

        for(auto it : mpp){

            res.push_back(it.second);
        }

        return res;
    }

};