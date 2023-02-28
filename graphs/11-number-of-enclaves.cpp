class Solution{
public:
    void travelInBoundary(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>& q, int N, int M){

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){

                if(i == 0 || j == 0 || i == N-1 || j == M-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>& q, int N, int M, vector<vector<int>>& delta){

        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<delta.size(); i++){

                int nrow = row + delta[i][0];
                int ncol = col + delta[i][1];

                if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    int findTheEnclaves(vector<vector<int>>& grid, vector<vector<int>>& vis, int N, int M){

        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){

                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }

    int numOfEnclaves(vector<vector<int>>& grid){

        int N = grid.size();
        int M = grid[0].size();

        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<pair<int, int>> q;

        // travel in boundary - rows and cols to get 1 
        travelInBoundary(grid, vis, q, N, M);

        vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bfs(grid, vis, q, N, M, delta);

        int numberOfEnclaves = findTheEnclaves(grid, vis, N, M);
        return numberOfEnclaves;
    }
};