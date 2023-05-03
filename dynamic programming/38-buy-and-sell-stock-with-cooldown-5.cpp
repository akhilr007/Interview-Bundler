class Solution {
public:
    int solve(int index, int canBuy, vector<int>& prices, int n, vector<vector<int>>& dp){

        if(index >= n) return 0;

        if(dp[index][canBuy] != -1)
            return dp[index][canBuy];

        int profit = 0;
        if(canBuy){
            int bought = -prices[index] + solve(index+1, 0, prices, n, dp);
            int notBought = 0 + solve(index+1, 1, prices, n, dp);

            profit = max(bought, notBought);
        }
        else{
            int sold = prices[index] + solve(index+2, 1, prices, n, dp);
            int notSold = 0 + solve(index+1, 0, prices, n, dp);

            profit = max(sold, notSold);
        }

        return dp[index][canBuy] = profit;
    }
    
    int tabulation(vector<int>& prices){
        
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        
        for(int index=n-1; index>=0; index--){
            for(int canBuy=0; canBuy<=1; canBuy++){

                int profit = 0;

                if(canBuy){

                    int bought = -prices[index] + dp[index+1][0];
                    int notBought = 0 + dp[index+1][1];

                    profit = max(bought, notBought);
                }
                else{

                    int sold = prices[index] + dp[index+2][1];
                    int notSold = 0 + dp[index+1][0];

                    profit = max(sold, notSold);
                }

                dp[index][canBuy] = profit;
            }
        }
        
        return dp[0][1];
    }
    
    int optimal(vector<int>& prices){
        
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        
        for(int index=n-1; index>=0; index--){
                
            int bought = -prices[index] + dp[index+1][0];
            int notBought = 0 + dp[index+1][1];

            // for buy -> 1
            dp[index][1] = max(bought, notBought);
            
            int sold = prices[index] + dp[index+2][1];
            int notSold = 0 + dp[index+1][0];

            // for sell -> 0
            dp[index][0] = max(sold, notSold);
            
        }
        
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return tabulation(prices);
    }
};