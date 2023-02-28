class Solution{
public:
    // time complexity -> O(N*M) space complexity -> O(N * M)
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& grid){

        int N = grid.size();
        int M = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int deltaRow=-1; deltaRow<=1; deltaRow++){
                for(int deltaCol=-1; deltaCol<=1; deltaCol++){

                    int newRow = row + deltaRow;
                    int newCol = col + deltaCol;

                    if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M &&
                     grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
                        q.push({newRow, newCol});
                        vis[newRow][newCol] = 1;
                    }
                }
            }
        }
    }

    int numberOfConnectedComponents(vector<vector<char>>& grid){
        // 0 -> water, 1-> land

        int N = grid.size();
        int M = grid[0].size();

        vector<vector<int>> vis(N, vector<int> (M, 0));
        int cnt=0;
        for(int row=0; row<N; row++){
            for(int col=0; col<M; col++){
                if(grid[i][j] == '1' && vis[row][col] == 0){
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return cnt;
    }
};