class Solution {
public:
    int solve(int i, int j, string& s, string& r, vector<vector<int>>& dp){
        
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans=0;
        if(s[i] == r[j])
            ans = 1 + solve(i-1, j-1, s, r, dp);
        else
            ans = max(solve(i-1, j, s, r, dp), solve(i, j-1, s, r, dp));
        
        return dp[i][j] = ans;
    }
    
    int tabulation(string s, string r){
        
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                
                int ans=0;
                if(s[i-1] == r[j-1])
                    ans = 1 + dp[i-1][j-1];
                else
                    ans = max(dp[i-1][j], dp[i][j-1]);
                
                dp[i][j] = ans;
            }   
        }
        
        return dp[n][n];
    }
    
    int optimal(string s, string r){
        
        int n = s.size();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                
                int ans=0;
                if(s[i-1] == r[j-1])
                    ans = 1 + prev[j-1];
                else
                    ans = max(prev[j], cur[j-1]);
                
                cur[j] = ans;
            }   
            prev = cur;
        }
        
        return prev[n];
    }
    
    int longestPalindromeSubsequence(string s) {
        
        int n = s.size();
        string r = s;
        reverse(begin(r), end(r));
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return optimal(s, r);
    }
};