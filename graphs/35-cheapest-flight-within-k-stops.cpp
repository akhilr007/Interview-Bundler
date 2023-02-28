class Solution{
public:
    // time complexity -> O(V + E)
    // space complexity -> O(N)
    int findCheapestPrice(int n, vector<int>& flights, int src, int dst, int k){

        vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({ 0, {src, 0}}); // [steps to reach, src_node, dis]

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int node = it.second.first;
            int dis = it.second.second;

            for(auto nbr: adj[node]){
                int adjNode = nbr.first;
                int edgeWeight = nbr.second;

                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    q.push({ steps + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};