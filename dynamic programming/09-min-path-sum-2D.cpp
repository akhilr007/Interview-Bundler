class Solution {
private:
    // time complexity -> O(2^(m*n))
    // space complexity -> O(length of path) -> O(m-1 + n-1)
    int utilRec(int i, int j, vector<vector<int>>& grid){
        
        if(i < 0 || j < 0) 
            return 1e8;
        if(i == 0 && j == 0)
            return grid[i][j];
        
        int up = grid[i][j] + utilRec(i-1, j, grid);
        int left = grid[i][j] + utilRec(i, j-1, grid);
        
        return min(up, left);
    }
    
    // time complexity -> O((m*n))
    // space complexity -> O(length of path + m*n) -> O(m-1 + n-1) + O(m*n)
    int t[201][201];
    int utilMem(int i, int j, vector<vector<int>>& grid){
        
        if(i < 0 || j < 0) 
            return 1e8;
        if(i == 0 && j == 0)
            return grid[i][j];
        if(t[i][j] != -1)
            return t[i][j];
        
        int up = grid[i][j] + utilMem(i-1, j, grid);
        int left = grid[i][j] + utilMem(i, j-1, grid);
        
        return t[i][j] = min(up, left);
    }
    
    // time complexity -> O((m*n))
    // space complexity -> O(m*n)
    int utilTab(vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == 0 and j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int up = 1e8, left = 1e8;
                if(i > 0) up = grid[i][j] + dp[i-1][j];
                if(j > 0) left = grid[i][j] + dp[i][j-1];
                
                dp[i][j] = min(up, left);
            }
        }
        
        return dp[m-1][n-1];
    }
    
public:
    // time complexity -> O(m*n)
    // space complexity -> O(n)
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n, 0), cur(n, 0);
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == 0 and j == 0){
                    cur[j] = grid[i][j];
                    continue;
                }
                
                int up = 1e8, left = 1e8;
                if(i > 0) up = grid[i][j] + prev[j];
                if(j > 0) left = grid[i][j] + cur[j-1];
                
                cur[j] = min(up, left);
            }
            
            prev = cur;
        }
        
        return prev[n-1];
    }
};