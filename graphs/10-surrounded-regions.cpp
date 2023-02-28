class Solution{
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, vector<vector<int>>& delta){

        vis[row][col] = 1;
        int N = board.size();
        int M = board[0].size();

        for(int i=0; i<delta.size(); i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];

            if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                dfs(nrow, ncol, board, vis, delta);
            }
        }
    }

    void surroundedRegions(vector<vector<char>>& board){

        int N = board.size();
        int M = board[0].size();

        vector<vector<int>> vis(N, vector<int> (M, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        // travel in boundary - rows
        for(int i=0; i<M; i++){
            if(board[0][i] == 'O' && vis[0][i] == 0){
                dfs(0, i, board, delta);
            }

            if(board[N-1][i] == 'O' && vis[N-1][i] == 0){
                dfs(N-1, i, board, vis, delta);
            }
        }

        // travel in boundary - column
        for(int i=0; i<N; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                dfs(i, 0, board, vis, delta);
            }

            if(board[i][M-1] == 'O' && vis[i][M-1] == 0){
                dfs(i, M-1, board, vis, delta);
            }
        }

        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};