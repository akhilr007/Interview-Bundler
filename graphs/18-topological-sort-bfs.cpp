class Solution{
public:
    // time complexity -> O(V + E)
    // space complexity -> O(V + V)
    vector<int> topologicalSort(vector<int> adj[], int V){

        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto node: adj[i]){
                indegree[node]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){

            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        return ans;

    }
};