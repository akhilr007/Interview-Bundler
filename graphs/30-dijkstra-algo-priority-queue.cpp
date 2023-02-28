class Solution{
public:
    // time complexity -> O(V + E*logV)
    // space complexity -> O(V for distance array + V for priority_queue) 
    vector<int> dijkstraAlgorithm(int V, vector<vector<int>> adj[], int src){

        vector<int> distance(V, 1e9);
        
        // we need min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // [distance, node]
        distance[src] = 0;

        while(!pq.empty()){

            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto edge: adj[node]){
                int edgeWeight = edge[1];
                int adjNode = edge[0];

                if(dist + edgeWeight < distance[adjNode]){
                    distance[adjNode] = dist + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        return distance;
    }
};