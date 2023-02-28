struct Pair{
    int row;
    int col;
    int diff;
    Pair(int diff, int row, int col){
        this->diff = diff;
        this->row = row;
        this->col = col;
    }
};

class Solution{
public:
    int minimumEffortPath(vector<vector<int>>& heights){

        // this solution we will be solving using comparator of priority queue
        // but in interview pair is preferred

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        // in priority_queue, use alter of normal compare like normal would be p1.diff <= p2.diff
        auto lambda = [&](Pair p1, Pair p2){
            return p1.diff >= p2.diff;
        };

        priority_queue<Pair, vector<Pair>, decltype(lambda)> pq(lambda);
        Pair p = Pair(0, 0, 0);
        pq.push(p);

        dist[0][0] = 0;

        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int diff = it.diff;
            int row = it.row;
            int col = it.col;

            if(row == n-1 and col == m-1) return diff;

            for(int i=0; i<4; i++){
                int nrow = row + dir[i][0];
                int ncol = col + dir[i][1];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){

                    int new_effort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(new_effort < dist[nrow][ncol]){
                        dist[nrow][ncol] = new_effort;
                        Pair p = Pair(dist[nrow][ncol], nrow, ncol);
                        pq.push(p);
                    }
                }
            }
        }

        return 0;

    }
};