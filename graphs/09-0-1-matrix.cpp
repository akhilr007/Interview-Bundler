class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int N = mat.size();
        int M = mat[0].size();
        
        vector<vector<int>> vis(N, vector<int> (M, 0));
        vector<vector<int>> dist(N, vector<int> (M, 0));
        queue<tuple<int, int, int>> q;
        
        // add all the zeros to queue
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int delta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while(!q.empty()){
            auto[row, col, nearestDistance] = q.front();
            dist[row][col] = nearestDistance;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delta[i][0];
                int ncol = col + delta[i][1];
                
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && vis[nrow][ncol]==0){
                    q.push({nrow, ncol, nearestDistance + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        return dist;
    }
};