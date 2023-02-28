class Solution{
public:
    // time complexity -> O(V + E) + O(N * LOGN)
    // space complexity -> O(N + N +N)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){

        int n = graph.size();
        // build reverse graph
        vector<int> graphRev[n];
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto node: graph[i]){
                graphRev[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto nbr: graphRev[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        sort(begin(safeNodes), end(safeNodes));
        return safeNodes;

    }
}