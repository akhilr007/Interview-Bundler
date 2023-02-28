class UnionFind {
public:
    vector<int> parent, size;
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
public:
    int numberOfProvince(int v, vector<vector<int>> adj){

        UnionFind uf(V);
        for(int i=0; i<adj.size(); adj.size()){
            for(int j=0; j<adj[0].size(); j++){
                if(adj[i][j] == 1){
                    uf.unionBySize(i, j);
                }
            }
        }

        int cnt=0;
        for(int i=0; i<V; i++){
            if(uf.parent[i] == i) cnt++;
        }

        return cnt;
    }
};