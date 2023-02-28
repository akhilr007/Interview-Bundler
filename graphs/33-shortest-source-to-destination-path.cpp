class Solution{
public:
    // time complexity -> (N * M) + (4 * N * M)
    // space complexity -> O(N * M)
    int shortestPath(int N, int M, vector<vector<int>>& A, int X, int Y){

        if(A[0][0] == 0) return -1;

        vector<vector<int>> dist(N, vector<int> (M, 1e9)); 

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}}); // {distance, {row, col}}

        dist[0][0] = 0;

        vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        // N * M
        while(!pq.empty()){

            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == X && col == Y) return dis;

            // 4 * (N * M)
            for(int d=0; d<4; d++){
                int nrow = row + delta[d][0];
                int ncol = col + delta[d][1];

                if(nrow >= 0 && ncol >= 0 && nrow < N && ncol < M && A[nrow][ncol] == 1){

                    if(dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        q.push({ dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        return -1;

    }
};