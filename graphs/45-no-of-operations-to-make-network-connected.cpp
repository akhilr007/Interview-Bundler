class UnionFind{
public:
    vector<int> size, parent;
    UnionFind(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
     
        UnionFind uf(n);
        
        int countExtraEdges = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            
            if(uf.findUltimateParent(u) == uf.findUltimateParent(v)){
                countExtraEdges++;
            }
            else{
                uf.unionBySize(u, v);
            }
        }
        
        int numberOfComponents=0;
        for(int i=0; i<n; i++){
            if(uf.parent[i] == i) numberOfComponents++;
        }
        
        int edgesRequiredToConnectEveryComponent = numberOfComponents-1;
        if(countExtraEdges >= edgesRequiredToConnectEveryComponent){
            return edgesRequiredToConnectEveryComponent;
        }
        
        return -1;
    }
};