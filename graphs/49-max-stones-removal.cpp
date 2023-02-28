class UnionFind{
public:
    vector<int> size, parent;
    UnionFind(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
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
    int stonesRemoved(vector<vector<int>>& stones){

        int n=stones.size();

        // calculate max_row and max_col in the grid
        int maxRow = 0;
        int maxCol = 0;

        for(auto stone: stones){
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // here row will be mapped as for maxRow = 3 we have nodes for row = 0, 1, 2, 3
        // here col will be mapped as for maxCol = 2 we have nodes for col = 4, 5, 6 -> for 0 col -> maxRow + col + 1 = 4

        UnionFind uf(maxRow + maxCol + 2); 
        
        unordered_map<int, int> stoneNode;
        // connect all the stone which fall in same row line and column line
        for(auto stone: stones){
            int nodeRow = stone[0];
            int nodeCol = maxRow + stone[1] + 1;

            uf.unionBySize(nodeRow, nodeCol);
            stoneNode[nodeRow] = 1;
            stoneNode[nodeCol] = 1;
        }

        int components=0;
        for(auto it: stoneNode){
            if(uf.findUltimateParent(it.first) == it.first) components++;
        }
        
        return n - components;
    }
}