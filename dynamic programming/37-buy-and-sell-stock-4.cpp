class Solution {
public:
    int solve(int index, int transactionNo, int k, vector<int>& prices,
             vector<vector<int>>& dp){
        
        if(index >= prices.size() || transactionNo == 2*k)
            return 0;
        
        if(dp[index][transactionNo] != -1)
            return dp[index][transactionNo];
        
        int profit = 0;
        if(transactionNo % 2 == 0){
            // buy
            int bought = -prices[index] + solve(index+1, transactionNo+1, k, prices, dp);
            int notBought = 0 + solve(index+1, transactionNo, k, prices, dp);
            
            profit = max(bought, notBought);
        }
        else{
            // sell
            int sold = prices[index] + solve(index+1, transactionNo+1, k, prices, dp);
            int notSold = 0 + solve(index+1, transactionNo, k, prices, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][transactionNo] = profit;
    }
    
    int tabulation(vector<int>& prices, int k){
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
        
        for(int index=n-1; index>=0; index--){
            
            for(int transactionNo=2*k-1; transactionNo>=0; transactionNo--){
                
                int profit = 0;
                if(transactionNo % 2 == 0){
                    // buy
                    int bought = -prices[index] + dp[index+1][transactionNo+1];
                    int notBought = 0 + dp[index+1][transactionNo];

                    profit = max(bought, notBought);
                }
                else{
                     // sell
                    int sold = prices[index] + dp[index+1][transactionNo+1];
                    int notSold = 0 + dp[index+1][transactionNo];

                    profit = max(sold, notSold);
                }
                
                dp[index][transactionNo] = profit;
            }
        }
        
        return dp[0][0];
    }
    
    int optimal(vector<int>& prices, int k){
        
        int n = prices.size();
        vector<int> ahead(2*k+1, 0), cur(2*k+1, 0);
        
        for(int index=n-1; index>=0; index--){
            
            for(int transactionNo=2*k-1; transactionNo>=0; transactionNo--){
                
                int profit = 0;
                if(transactionNo % 2 == 0){
                    // buy
                    int bought = -prices[index] + ahead[transactionNo+1];
                    int notBought = 0 + ahead[transactionNo];

                    profit = max(bought, notBought);
                }
                else{
                     // sell
                    int sold = prices[index] + ahead[transactionNo+1];
                    int notSold = 0 + ahead[transactionNo];

                    profit = max(sold, notSold);
                }
                
                cur[transactionNo] = profit;
            }
            ahead = cur;
        }
        
        return ahead[0];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return optimal(prices, k);
    }
};