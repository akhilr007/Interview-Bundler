// time complexity -> O(v + e)
// space complexity -> O(n)
class Solution{
private:
    int timer=0;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis,
            int tin[], int low[], vector<vector<int>>& bridges){

        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it: adj[node]){

            if(it == parent) continue;

            if(vis[it] == 0){
                dfs(it, node, adj, vis, tin, low, bridges);

                low[node] = min(low[node], low[it]);

                if(low[it] > tin[node]){
                    bridges.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }   
        }
     }

public:
    vector<vector<int>> findBridges(int n, vector<vector<int>>& connections){

        vector<int> adj[n];

        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];

        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};