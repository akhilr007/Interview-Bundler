class Solution{
public:
    int mod = 1003;
    int solve(int i, int j, int isTrue, string& s, vector<vector<vector<int>>>& dp){
        
        if( i > j) return 0;
        
        if(i == j){
            
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        
        long long ways = 0;
        
        for(int k=i+1; k<=j-1; k+=2){
            
            int lT = solve(i, k-1, 1, s, dp);
            int rT = solve(k+1, j, 1, s, dp);
            int lF = solve(i, k-1, 0, s, dp);
            int rF = solve(k+1, j, 0, s, dp);
            
            if(s[k] == '&'){
                
                if(isTrue){
                    ways = (ways + (lT * rT) % mod) % mod;
                }
                else{
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
            
            else if(s[k] == '|'){
                
                if(isTrue){
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                }
                else{
                    ways = (ways + (lF * rF) % mod) % mod;
                }
            }
            else{
                
                if(isTrue){
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                }
                else{
                    ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int tabulation(int N, string s){
        
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (2, 0)));
        

        
        for(int i=N-1; i>=0; i--){
            
            for(int j=0; j<=N-1; j++){
                
                for(int isTrue=0; isTrue<=1; isTrue++){
                    
                    
                    if(i > j) continue;
                    if(i == j){
                        
                        dp[i][j][1] = s[i] == 'T';
                        dp[i][j][0] = s[i] == 'F';
                        
                        continue;
                    }
                    
                    long long ways = 0;
                    
                    for(int k=i+1; k<=j-1; k+=2){
                        
                        int lT = dp[i][k-1][1];
                        int rT = dp[k+1][j][1];
                        int lF = dp[i][k-1][0];
                        int rF = dp[k+1][j][0];
                        
                        if(s[k] == '&'){
                            
                            if(isTrue){
                                ways = (ways + (lT * rT) % mod) % mod;
                            }
                            else{
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                            }
                        }
                        
                        else if(s[k] == '|'){
                            
                            if(isTrue){
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                            }
                            else{
                                ways = (ways + (lF * rF) % mod) % mod;
                            }
                        }
                        else{
                            
                            if(isTrue){
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                            }
                            else{
                                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                            }
                        }
                    }
                    
                    
                    dp[i][j][isTrue] = ways;
                    
                }
            }
        }
        
        return dp[0][N-1][1];
    }
    
    int countWays(int N, string s){
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (2, -1)));
        return solve(0, N-1, 1, s, dp);
    }
};