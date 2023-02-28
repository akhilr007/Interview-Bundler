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
private:
    bool isValid(int r, int c, int n, int m){
        return r>=0 && r<n && c>=0 && c<m;
    }
    
public:
    // time complexity-> O(n * 4-alpha)
    vector<int> numberOfIslandsII(int n, int m, vector<Point>& operators){

        UnionFind uf(n*m);

        int vis[n][m];
        memset(vis, 0, sizeof vis);

        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int cnt=0;

        vector<int> ans;

        for(auto it : operators){

            int row = it.x;
            int col = it.y;

            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            for(int d=0; d<4; d++){

                int new_row = row + dir[d][0];
                int new_col = col + dir[d][1];

                if(isValid(new_row, new_col, n, m)){
                    if(vis[new_row][new_col] == 1){

                        int nodeNo = (row * m) + col;
                        int adjNodeNo = (new_row * m) + new_col;

                        if(uf.findUltimateParent(nodeNo) != uf.findUltimateParent(adjNodeNo)){
                            cnt--;
                            uf.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};