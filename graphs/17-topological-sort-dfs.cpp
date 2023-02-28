class Solution{
public: 
    // time complexity -> O(V + E)
    // space complexity -> O(N + N)
    void dfs(int node, vector<int> adj[], int vis[], stack<int>& st){

        vis[node] = 1;
        for(auto nbr: adj[node]){
            if(vis[nbr] == 0){
                dfs(nbr, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> topologicalSort(vector<int> adj[], int V){

        int vis[V];
        for(int i=0; i<V; i++) vis[i] = 0;

        stack<int> st;
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};