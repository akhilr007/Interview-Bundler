class Solution{
public:     
    // time complexity -> O(V + 2E)
    // space complexity -> O(V)
    bool detect(int node, int V, vector<int> adj[], bool vis[]){

        queue<pair<int, int>> q; // pair -> [node, parent]
        q.push({node, -1});
        vis[node] = true;

        while(!q.empty()){

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode: adj[node]){
                if(vis[adjacentNode] == false){
                    q.push({adjacentNode, node});
                    vis[adjacentNode] = true;
                }
                // if the adjacent node is visited and it is not parent then it is a cycle as it has
                // been visited through some other node
                else if(adjacentNode != parent){
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]){

        bool vis[V] = {false};
        for(int i=0; i<V; i++){
            if(vis[i] == false){
                if(detect(i, V, adj, vis) == true) return true;
            }
        }

        return false;
    }
};