class Solution{
public:
    typedef pair<int, int> pii;
    vector<int> findShortestPath(int n, int m, vector<vector<int>> edges){

        // build adjacency matrix
        vector<pair<int, int>> adj[n+1]; // 1-based graph
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;


        dist[1] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1}); // [distance, source_node]

        while(!pq.empty()){

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;

                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({ dist[adjNode], adjNode });
                    parent[adjNode] = node;
                }
            }
        }

        if(dist[n] == 1e9) return {-1};
        int node = n;

        vector<int> path;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
        
    }
};