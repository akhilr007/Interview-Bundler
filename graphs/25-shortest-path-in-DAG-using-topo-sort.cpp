class Solution{
public:
    // time complexity -> O(N + M)
    // space complexity -> O(N + N + N)
    void topoSortDfs(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st){

        vis[node] = 1;
        for(auto nbr: adj[node]){
            int v = nbr.first;
            if(!vis[v]){
                topoSortDfs(v, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<int> edges[]){

        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        vector<int> vis(N, 0);
        stack<int> st;

        // topological sort -> O(N + M)
        for(int i=0; i<N; i++){
            if(!vis[i])
                topoSortDfs(i, adj, vis, st);
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0; // if src is given put dist[src] = 0

        // O(N + M)
        while(!st.empty()){

            int node = st.top();
            st.pop();

            for(auto nbr: adj[node]){
                int v = nbr.first;
                int wt = nbr.second;

                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }

        for(int i=0; i<N; i++){
            if(dist[i] == 1e9) dist[i] = -1; // unvisited nodes
        }

        return dist;
    }
};