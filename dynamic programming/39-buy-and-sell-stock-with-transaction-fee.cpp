class Solution {
public:
    int solve(int index, int canBuy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        
        if(index >= prices.size())
            return 0;
        
        if(dp[index][canBuy] != -1)
            return dp[index][canBuy];
        
        int profit = 0;
        if(canBuy){
            
            int bought = -prices[index] + solve(index+1, 0, fee, prices, dp);
            int notBought = 0 + solve(index+1, 1, fee, prices, dp);
            
            profit = max(bought, notBought);
        }
        else{
            
            int sold = prices[index] - fee + solve(index+1, 1, fee, prices, dp);
            int notSold = 0 + solve(index+1, 0, fee, prices, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][canBuy] = profit;
    }
    
    int tabulation(vector<int>& prices, int fee){
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        
        for(int index=n-1; index>=0; index--){
            
            for(int canBuy=0; canBuy<=1; canBuy++){
                
                int profit = 0;
                
                if(canBuy){
                    int bought = -prices[index] + dp[index+1][0];
                    int notBought = 0 + dp[index+1][1];

                    profit = max(bought, notBought);
                }
                else{
                    int sold = prices[index] - fee + dp[index+1][1];
                    int notSold = 0 + dp[index+1][0];

                    profit = max(sold, notSold);
                }
                dp[index][canBuy] = profit;
            }
        }
        
        return dp[0][1];
    }
    
    int optimal(vector<int>& prices, int fee){
        
        int n = prices.size();
        
        vector<int> ahead(2, 0), cur(2, 0);
        
        for(int index=n-1; index>=0; index--){
            
            for(int canBuy=0; canBuy<=1; canBuy++){
                
                int profit = 0;
                
                if(canBuy){
                    int bought = -prices[index] + ahead[0];
                    int notBought = 0 + ahead[1];

                    profit = max(bought, notBought);
                }
                else{
                    int sold = prices[index] - fee + ahead[1];
                    int notSold = 0 + ahead[0];

                    profit = max(sold, notSold);
                }
                cur[canBuy] = profit;
            }
            
            ahead = cur;
        }
        
        return ahead[1];
    }
    
    int mostOptimal(vector<int>& prices, int fee){
        
        int n = prices.size();
        
        vector<int> ahead(2, 0), cur(2, 0);
        
        for(int index=n-1; index>=0; index--){
            
            // we can remove canBuy loop as it runs for only 0 and 1
            // so cur[1] for buy and cur[0] -> for sell
            int bought = -prices[index] + ahead[0];
            int notBought = 0 + ahead[1];

            cur[1] = max(bought, notBought);

            int sold = prices[index] - fee + ahead[1];
            int notSold = 0 + ahead[0];
            
            cur[0] = max(sold, notSold);

            ahead = cur;
        }
        
        return ahead[1];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return mostOptimal(prices, fee);
    }
};