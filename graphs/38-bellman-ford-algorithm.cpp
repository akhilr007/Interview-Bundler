// it works on -ve weights and can detect that the graph has -ve cycle or not
// at max it takes n-1 iterations to find the shortest path it the edges are sorted it takes 1 iteration
class Solution{
public:
    // time complexity -> O(V * E)
    // space complexity -> O(V)
    vector<int> bellmanFord(int src, vector<vector<int>>& edges, int V){

        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // nth iteration to check if the graph has -ve cycle or not, i.e, if dist are further reduced we
        // can say that a -ve cycle is present
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};