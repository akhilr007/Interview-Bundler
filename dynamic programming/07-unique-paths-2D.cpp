class Solution {
private:
    // time complexity -> O(2^(m*n))
    // space complexity -> O(length of path (m-1 + n-1))
    int utilRec(int i, int j){
        
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        int up = utilRec(i-1, j);
        int left = utilRec(i, j-1);
        
        return up + left;
    }
    
    // time complexity -> O(m*n)
    // space complexity -> O(m-1 + n-1) + O(m*n)
    int t[101][101];
    int utilMem(int i, int j){
        
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        
        int up = utilMem(i-1, j);
        int left = utilMem(i, j-1);
        
        return t[i][j] = up + left;
    }
    
    int utilTab(int m, int n){
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                
                dp[i][j] = up + left;
            }
        }
        
        return dp[m-1][n-1];
    }
    
public:
    // time complexity -> O(m * n)
    // space complexity -> O(n)
    int uniquePaths(int m, int n) {
        
        vector<int> prev(n, 0), cur(n, 0);
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == 0 && j == 0){
                    cur[j] = 1;
                    continue;
                }
                
                int up = 0, left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j-1];
                
                cur[j] = up + left;
            }
            prev = cur;
        }
        
        return prev[n-1];
    }
};