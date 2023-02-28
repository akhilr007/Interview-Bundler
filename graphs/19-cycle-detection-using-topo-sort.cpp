class Solution{
public:
    bool isCyclic(vector<int> adj[], int V){

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

        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        if(cnt == V) return false; // not cyclic
        return true;
    }
};