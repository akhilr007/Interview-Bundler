class Solution{
public:
    // time complexity -> (v + e) log v
    // space complexity - o(V)
    int calculateMST(vector<vector<int>> adj, int V){

        priority_queue<pair<int, int>>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // [wt , node]

        int mst=0;
        vector<int> vis(v, 0);
        
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if(vis[node] == 1) continue;

            vis[node] = 1;
            mst += wt;

            for(auto it : adj[node]){
                int adjNode = it[0];
                int eWt = it[1];
                pq.push({eWt, adjNode});
            }
        }

        return mst;
    }
};