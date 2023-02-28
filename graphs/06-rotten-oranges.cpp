class Solution{
public:
    // time complexity -> O(N*M + 4(N*M))
    // space complexity -> O(N*M)
    int calculateFreshOrangesAndAddRottenOranges(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<tuple<int, int, int> >& q){

        int cnt=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){

                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1) cnt++;
            }
        }

        return cnt;
    }

    int orangesRotting(vector<vector<int>>& grid){

        int N = grid.size();
        int M = grid[0].size();

        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<tuple<int, int, int>> q;
        int freshOranges = calculateFreshOrangesAndAddRottenOranges(grid, vis, q);

        if(freshOranges == 0) return 0;

        int delta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int time=0;
        while(!q.empty()){

            auto [row, col, tm] = q.front();
            q.pop();
            time = max(time, tm);

            for(int i=0; i<4; i++){
                int newRow = row + delta[i][0];
                int newCol = col + delta[i][1];

                if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && grid[newRow][newCol] == 1 && vis[newRow][newCol] != 2){
                    q.push({newRow, newCol, tm + 1});
                    vis[newRow][newCol] = 2;
                    freshOranges--;
                }
            }
        }

        if(freshOranges == 0) return time;
        return -1;
    }
};