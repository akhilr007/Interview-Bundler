class Solution{
public:
    // time complexity -> O(V + 2E)
    // space complexity -> O(V + V for recursion stack)
    bool detectCycle(int node, int parent, vector<int> adj[], bool vis[]){

        vis[node] = true;
        for(auto adjacentNode: adj[node]){
            if(vis[adjacentNode] == false){
                if(detectCycle(adjacentNode, node, adj, vis) == true) return true;
            }
            else if(adjacentNode != parent) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){

        bool vis[V] = {false};
        for(int i=0; i<V; i++){
            if(vis[i] == false){
                if(detectCycle(i, -1, adj, vis) == true) return true;
            }
        }

        return false;
    }
};