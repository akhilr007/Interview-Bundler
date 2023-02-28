class Solution{
public: 
    vector<int> dijkstraAlgorithm(int V, vector<vector<int>> adj[], int src){

        vector<int> dist(V, 1e9);
        set<pair<int, int>> st;

        st.insert({0, src});
        dist[src] = 0;

        while(!st.empty()){

            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto nbr: adj[node]){
                int adjNode = nbr[0];
                int edgeWeight = nbr[1];

                if(dis + edgeWeight < dist[adjNode]){
                    
                    // if we have some large
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({ dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};