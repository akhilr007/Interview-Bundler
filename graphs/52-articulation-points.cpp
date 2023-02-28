class Solution{
private:
    int timer=0;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis,
     vector<int>& mark, int low[], int tin[]){

        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child=0;
        for(auto it : adj[node]){
            if(it == parent) continue;

            if(!vis[it]){
                dfs(it, node, adj, vis, mark, low, tin);

                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }

        if(child > 1 && parent == -1){
            mark[node] = -1;
        }
     }

public:
    vector<int> findArticulationPoints(int n, vector<int> adj[]){

        vector<int> vis(n, 0);
        int low[n];
        int tin[n];
        vector<int> mark(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, mark, low, tin);
            }
        }

        vector<int> res;
        for(int i=0; i<n; i++){
            if(mark[i] == 1) res.push_back(i);
        }

        if(res.size() == 0) return {-1};
        return res;

    }
};