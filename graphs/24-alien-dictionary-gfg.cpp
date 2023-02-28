class Solution{
public:
    string topologicalSort(int V, vector<int> adj[]){

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

        string ans="";
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        if(ans.length() == K) return ans;
        return "";
    }

    string alienOrder(vector<string>& words, int N, int K){

        vector<int> adj[K];
        for(int i=0; i<N-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.length(), s2.length());
            for(int p=0; p<len; p++){

                if(s1[p] != s2[p]){
                    adj[s1[p] - 'a'].push_back(s2[p] - 'a');
                    break;
                }
            }
        }

        return topologicalSort(K, adj);
    }
}