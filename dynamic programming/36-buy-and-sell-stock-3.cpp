class Solution {
public:
    int solve(int index, int canBuy, int cap, vector<int>& prices, int n,
             vector<vector<vector<int>>>& dp){
        
        if(index >= n || cap == 0)
            return 0;
        
        if(dp[index][canBuy][cap] != -1)
            return dp[index][canBuy][cap];
        
        int profit=0;
        if(canBuy){
            int bought = -prices[index] + solve(index+1, 0, cap, prices, n, dp);
            int notBought = 0 + solve(index+1, 1, cap, prices, n, dp);
            
            profit = max(bought, notBought);
        }
        else{
            int sold = prices[index] + solve(index+1, 1, cap-1, prices, n, dp);
            int notSold = 0 + solve(index+1, 0, cap, prices, n, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][canBuy][cap] = profit;
    }
    
    int tabulation(vector<int>& prices){
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        for(int index=n-1; index>=0; index--){
            
            for(int canBuy=0; canBuy<=1; canBuy++) {
                
                // for every cap = 0 , result will be 0 so no point of starting with it
                for(int cap=1; cap<=2; cap++){
                    
                    int profit=0;
                    if(canBuy){
                        int bought = -prices[index] + dp[index+1][0][cap];
                        int notBought = 0 + dp[index+1][1][cap];

                        profit = max(bought, notBought);
                    }
                    else{
                        int sold = prices[index] + dp[index+1][1][cap-1];
                        int notSold = 0 + dp[index+1][0][cap];

                        profit = max(sold, notSold);
                    }

                    dp[index][canBuy][cap] = profit;
                    
                }
                
                
            }
        }
        
        return dp[0][1][2];
    }
    
    int optimal(vector<int>& prices){
        
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int> (3, 0));
        vector<vector<int>> cur(2, vector<int> (3, 0));
        
        for(int index=n-1; index>=0; index--){
            
            for(int canBuy=0; canBuy<=1; canBuy++) {
                
                // for every cap = 0 , result will be 0 so no point of starting with it
                for(int cap=1; cap<=2; cap++){
                    
                    int profit=0;
                    if(canBuy){
                        int bought = -prices[index] + ahead[0][cap];
                        int notBought = 0 + ahead[1][cap];

                        profit = max(bought, notBought);
                    }
                    else{
                        int sold = prices[index] + ahead[1][cap-1];
                        int notSold = 0 + ahead[0][cap];

                        profit = max(sold, notSold);
                    }

                    cur[canBuy][cap] = profit;
                    
                }
                
                ahead = cur;
            }
        }
        
        return ahead[1][2];
    }
    
    int solveT(int index, int ts, vector<int>& prices, int n, vector<vector<int>>& dp){
        
        if(index >= n || ts >= 4)
            return 0;
        
        if(dp[index][ts] != -1)
            return dp[index][ts];
        
        int profit = 0;
        if(ts % 2 == 0){
            // buy
            int bought = -prices[index] + solveT(index+1, ts+1, prices, n, dp);
            int notBought = 0 + solveT(index+1, ts, prices, n, dp);
            
            profit = max(bought, notBought);
        }
        else{
            // sell
            int sold = prices[index] + solveT(index+1, ts+1, prices, n, dp);
            int notSold = 0 + solveT(index+1, ts, prices, n, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][ts] = profit;
    }
    
    int tabulationT(vector<int>& prices){
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int> (5, 0));
        
        for(int index=n-1; index>=0; index--){
            for(int ts=3; ts>=0; ts--){
                
                int profit = 0;
                if(ts%2 == 0){
                    // buy
                    int bought = -prices[index] + dp[index+1][ts+1];
                    int notBought = 0 + dp[index+1][ts];

                    profit = max(bought, notBought);
                }
                else{
                    // sell
                    int sold = prices[index] + dp[index+1][ts+1];
                    int notSold = 0 + dp[index+1][ts];

                    profit = max(sold, notSold);
                }
                
                dp[index][ts] = profit;
            }
        }
        
        return dp[0][0];
    }
    
    int optimalT(vector<int>& prices){
        
        int n = prices.size();
        
        vector<int> ahead(5, 0), cur(5, 0);
        
        for(int index=n-1; index>=0; index--){
            for(int ts=3; ts>=0; ts--){
                
                int profit = 0;
                if(ts%2 == 0){
                    // buy
                    int bought = -prices[index] + ahead[ts+1];
                    int notBought = 0 + ahead[ts];

                    profit = max(bought, notBought);
                }
                else{
                    // sell
                    int sold = prices[index] + ahead[ts+1];
                    int notSold = 0 + ahead[ts];

                    profit = max(sold, notSold);
                }
                
                cur[ts] = profit;
            }
            ahead = cur;
        }
        
        return ahead[0];
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        //vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        //return optimal(prices);
        
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return optimalT(prices);
    }
};