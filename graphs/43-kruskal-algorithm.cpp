class UnionFind {
private:
    vector<int> parent, size;
public:
    UnionFind(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){

        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV) return;

        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};

class Solution{
int kruskalAlgorithm(int V, vector<vector<int>> adj[]){

    vector<pair<pair<int, int>>> edges;
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(begin(edges), end(edges));
    int mst = 0;
    UnionFind uf(V);

    for(auto it : edges){

        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(uf.findUltimateParent(u) != uf.findUltimateParent(v)){
            mst += wt;
            uf.unionBySize(u, v);
        }
    }
    return mst;
}
}