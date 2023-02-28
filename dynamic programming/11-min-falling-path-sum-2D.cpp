class Solution {
public:
    // time complexity -> O(3^n)
    // space complexity -> O(n)
    int utilRec(int i, int j, vector<vector<int>>& matrix, int n){
        
        if(j<0 || j>=n)
            return 1e8;
        if(i == 0)
            return matrix[i][j];
        
        int move_up = matrix[i][j] + utilRec(i-1, j, matrix, n);
        int move_diag_left = matrix[i][j] + utilRec(i-1, j-1, matrix, n);
        int move_diag_right = matrix[i][j] + utilRec(i-1, j+1, matrix, n);
        
        return min(move_up, min(move_diag_left, move_diag_right));
    }
    
    // time complexity -> O(n * n)
    // space complexity -> O(n) + O(n * n)
    int t[101][101];
    int utilMem(int i, int j, vector<vector<int>>& matrix, int n){
        
        if(j<0 || j>=n)
            return 1e8;
        if(i == 0)
            return matrix[i][j];
        if(t[i][j] != -1)
            return t[i][j];
        
        int move_up = matrix[i][j] + utilMem(i-1, j, matrix, n);
        int move_diag_left = matrix[i][j] + utilMem(i-1, j-1, matrix, n);
        int move_diag_right = matrix[i][j] + utilMem(i-1, j+1, matrix, n);
        
        return t[i][j] = min(move_up, min(move_diag_left, move_diag_right));
    }
    
    // time complexity -> O(n * n)
    // space complexity -> O(n * n)
    int utilTab(vector<vector<int>>& matrix){
        
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        // base case -> (i == 0) then matrix[i][j]
        for(int j=0; j<n; j++)
            dp[0][j] = matrix[0][j];
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                int move_up = 1e8, move_diag_left=1e8, move_diag_right=1e8;
                
                if(i>0) move_up = matrix[i][j] + dp[i-1][j];
                if(i>0 && j>0) move_diag_left = matrix[i][j] + dp[i-1][j-1];
                if(i>0 && j+1<n) move_diag_right = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min({ move_up, move_diag_left, move_diag_right });
            }
        }
        
        int result = INT_MAX;
        for(int j=0; j<n; j++){
            result = min(dp[n-1][j], result);
        }
        return result;
    }
    
    // time complexity -> O(n * n)
    // space complexity -> O(n)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<int> back(n, 0), cur(n, 0);
        
        // base case -> (i == 0) then matrix[i][j]
        for(int j=0; j<n; j++)
            back[j] = matrix[0][j];
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                int move_up = 1e8, move_diag_left=1e8, move_diag_right=1e8;
                
                if(i>0) move_up = matrix[i][j] + back[j];
                if(i>0 && j>0) move_diag_left = matrix[i][j] + back[j-1];
                if(i>0 && j+1<n) move_diag_right = matrix[i][j] + back[j+1];
                
                cur[j] = min({ move_up, move_diag_left, move_diag_right });
            }
            
            back = cur;
        }
        
        int result = INT_MAX;
        for(int j=0; j<n; j++){
            result = min(back[j], result);
        }
        return result;
    }
};