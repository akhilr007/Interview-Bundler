class Solution{
public:
    vector<int> shortestPath(vector<int> edges[], int N, int M, int src){

        vector<int> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, 1e9);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nbr: adj[node]){
                
                if(dist[node] + 1 < dist[nbr]){
                    dist[nbr] = 1 + dist[node];
                    q.push(nbr);
                }
            }
        }

        for(int i=0; i<N; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
}