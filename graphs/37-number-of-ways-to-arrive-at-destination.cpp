class Solution{
public:
    int countPaths(int n, vector<vector<int>>& roads){

        vector<pair<long, long>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({ it[1], it[2] });
            adj[it[1]].push_back({ it[0], it[2] });
        }

        vector<long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long, long> vector<pair<long, long>> greater<pair<long, long>>> pq;
        pq.push({0, 0}); // [dist, node]

        long mod = 1e9+7;

        while(!pq.empty()){

            long dis = pq.top().first;
            long node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                long adjNode = it.first;
                long edgeWt = it.second;

                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({ dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edgeWt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return (int)ways[n-1] % mod;
    }
}