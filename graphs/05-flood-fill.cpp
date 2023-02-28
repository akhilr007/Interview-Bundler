/**
image we have X = N*M nodes
so we have grid where every cell is suppose 2, and we have to make 3.
so it will go for X nodes 
and for each X node node it will check in 4 directions so 4X
so time complexity will be (X + 4X) -> (N*M + 4(N*M))
and space complexity will be N*M for ans and recursion will go for N*M
*/
class Solution{
public:
    void dfs(int row, int col, vector<vector<int>>& ans, int newColor, 
    vector<vector<int>>& delta, int initialColor, vector<vector<int>>& image){

        ans[row][col] = newColor;
        int n = ans.size();
        int m = ans[0].size();

        for(int i=0; i<delta.size(); i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, newColor, delta, initialColor, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){

        if(image[sr][sc] == color) return image;

        vector<vector<int>> ans = image;
        vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // direction to move in grid
        int initialColor = image[sr][sc];

        dfs(sr, sc, ans, newColor, delta, initialColor, image);

        return ans;
    }
};