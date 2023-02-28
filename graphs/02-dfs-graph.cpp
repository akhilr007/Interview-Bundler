class Solution{
public:
    // time complexity -> O(N + 2E) space complexity -> O(N + N + N) -> O(N)
    
    void dfs(int node, vector<int> adj[], bool vis[], vector<int>& list){

        vis[node] = true;
        list.push_back(node);

        for(auto nbr: adj[node]){
            if(vis[nbr] == false){
                dfs(nbr);
            }
        }
    }

    vector<int> dfsOfGraph(int N, vector<int> adj[]){

        bool vis[N]={false};

        int start=0;
        vector<int> list;

        dfs(start, adj, vis, list);
        return list; 
    }
};