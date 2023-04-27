class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>> &dp) {

        if(index == 0)
            return amount % coins[0] == 0;

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int not_taken = solve(index-1, amount, coins, dp);

        int taken = 0;
        if(coins[index] <= amount)
            taken = solve(index, amount-coins[index], coins, dp);

        return dp[index][amount] = not_taken + taken;
    }

    int tabulation(vector<int> coins, int amount){

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0)
                dp[0][a] = 1;
        }

        for(int index=1; index<n; index++) {

            for(int a=0; a<=amount; a++){

                int not_taken = dp[index-1][a];

                int taken = 0;
                if(coins[index] <= a)
                    taken = dp[index][a-coins[index]];

                dp[index][a] = not_taken + taken;
            }
        }

        return dp[n-1][amount];
    }

    int optimal(vector<int> coins, int amount){

        int n = coins.size();
        vector<int> prev(amount+1, 0), cur(amount+1, 0);

        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0)
                prev[a] = 1;
        }

        for(int index=1; index<n; index++) {

            for(int a=0; a<=amount; a++){

                int not_taken = prev[a];

                int taken = 0;
                if(coins[index] <= a)
                    taken = cur[a-coins[index]];

                cur[a] = not_taken + taken;
            }

            prev = cur;
        }

        return prev[amount];
    }

    int coinChange2(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};