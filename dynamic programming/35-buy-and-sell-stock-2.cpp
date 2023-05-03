class Solution{
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
            int sold = prices[index] + solve(index+1, 1, prices, n, dp);
            int notSold = 0 + solve(index+1, 0, prices, n, dp);

            profit = max(sold, notSold);
        }

        return dp[index][canBuy] = profit;
    }

    int tabulation(vector<int>& prices){

        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int index=n-1; index>=0; index--){

            for(int canBuy=0; canBuy<=1; canBuy++){

                int profit = 0;
                if(canBuy){
                    int bought = -prices[index] + dp[index+1][0];
                    int notBought = 0 + dp[index+1][1];

                    profit = max(bought, notBought);
                }
                else{
                    int sold = prices[index] + dp[index+1][1];
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

        vector<int> ahead(2, 0), cur(2, 0);

        ahead[0] = ahead[1] = 0;

        for(int index=n-1; index>=0; index--){

            for(int canBuy=0; canBuy<=1; canBuy++){

                int profit = 0;
                if(canBuy){
                    int bought = -prices[index] + ahead[0];
                    int notBought = 0 + ahead[1];

                    profit = max(bought, notBought);
                }
                else{
                    int sold = prices[index] + ahead[1];
                    int notSold = 0 + ahead[0];

                    profit = max(sold, notSold);
                }

                cur[canBuy] = profit;
            }

            ahead = cur;
        }

        return ahead[1];
    }

    int mostOptimal(vector<int>& prices){

        int n = prices.size();

        int aheadBuy, aheadNotBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;

        for(int index=n-1; index>=0; index--){

            int bought = -prices[index] + aheadNotBuy;
            int notBought = 0 + aheadBuy;

            curBuy = max(bought, notBought);
        
        
            int sold = prices[index] + aheadBuy;
            int notSold = 0 + aheadNotBuy;

            curNotBuy = max(sold, notSold);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
            
        }

        return aheadBuy;
    }

    int greedy(vector<int>& prices){

        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++){

            if(prices[i] > prices[i-1]){
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }

    int maxProfit(vector<int>& prices){

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, prices, n, dp);

        // solve(0, 1) -> from 0th index if we buy what is the max profit we can get
    }
};