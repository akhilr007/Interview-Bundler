class Solution{
public:
// time complexity -> O(N + 2E) -> O(N + E) for every vertex it will travel to all its degree
// so total degree = 2E
// space complexity -> O(N) for queue and visited array
    vector<int> bfsOfGraph(int N, vector<int> adj[]){

        bool vis[N] = {false}; // visited array

        queue<int> q;
        q.push(0); // starting node, i.e, 0
        vis[0] = true;

        vector<int> bfs;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            bfs.push_back(node);

            for(auto nbr: adj[node]){
                if(vis[nbr] == false){
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }

        return bfs;
    }
};