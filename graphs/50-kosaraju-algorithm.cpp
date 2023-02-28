class Solution{
private:
    // time complexity-> O(V + E)
    // space complexity -> O(v)
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st){

        vis[node] = 1;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis, st);
            }
        }

        st.push(node);
    }

    void dfs2(int node, vector<int> adjT[], vector<int>& vis){

        vis[node] = 1;
        for(auto adjNode: adjT[node]){
            if(!vis[adjNode]){
                dfs2(adjNode, adjT, vis);
            }
        }
    }

public:
    int kosarajuAlgorithm(int V, vector<int> adj[]){

        vector<int> vis(V, 0);
        stack<int> st;

        // sort the nodes according to the finishing time
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        // reverse all the edges
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }

        // make a dfs call
        int scc=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!vis[node]){
                scc++;
                dfs2(node, adjT, vis);
            }
        }

        return scc;

    }
}