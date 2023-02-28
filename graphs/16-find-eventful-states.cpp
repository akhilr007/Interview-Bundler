class Solution{
public:
    // time complexity -> O(V + E)
    // space complexity -> O(2V)
    bool dfsCheck(int node, vector<vector<int>> adj, int vis[], int pathVis[]){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto adjacentNode: adj[node]){
            if(vis[adjacentNode] == false){
                if(dfsCheck(adjacentNode, adj, vis, pathVis) == true){
                    return true;
                }
            }
            else if(pathVis[adjacentNode] == 1) return true;
        }

        pathVis[node] = 0;
        return false;
    }

    bool isCycle(vector<vector<int>> adj, int V){

        int vis[V] = {0};
        int pathVis[V] = {0};

        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                dfsCheck(i, adj, vis, pathVis);
            }
        }

        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(pathVis[i] == 0) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};