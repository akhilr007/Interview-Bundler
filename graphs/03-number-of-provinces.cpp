class Solution{
public:
    // time complexity -> O(N + (N + 2E) for dfs) space complexity -> O(N+N(recursion stack))
    void dfs(int node, vector<int> adj[], vector<bool>& vis){

        vis[node] = true;
        for(auto nbr: adj[node]){
            if(vis[nbr] == false){
                dfs(nbr, adj, vis);
            }
        }
    }

    int numberOfProvinces(int N, vector<vector<int>>& adj){

        // create the adjacency list
        vector<int> adj[N+1]; // 1 based indexing
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(adj[i][j] == 1 && i != j){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool> vis(N+1, false);
        int count=0;

        for(int i=1; i<=N; i++){
            if(vis[i] == false){
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};