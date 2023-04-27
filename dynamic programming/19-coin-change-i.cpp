class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>> & dp) {

        // agar target 12 hai aur ek hi coin hai jiska value 4 hai to kitna coin lagega 
        // ans hai target / coins[0];
        if(index == 0){
            if(amount % coins[0])
                return amount / coins[0];

            return 1e8;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int not_taken = solve(index-1, amount, coins, dp);

        int taken = 1e8;
        if(coins[index] <= amount)
            taken = 1 + solve(index, amount-coins[index], coins, dp);

        return dp[index][amount] = min(not_taken, taken);
    }

    int tabulation(vector<int> coins, int amount){

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 1e8));

        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0)
                dp[0][a] = a / coins[0];
        }

        for(int index=1; index<n; index ++){

            for(int a=0; a<=amount; a++) {

                int not_taken = dp[index-1][a];

                int taken = 1e8;
                if(coins[index] <= a)
                    taken = 1 + dp[index][a-coins[index]];

                dp[index][a] = min(not_taken, taken);
            }
        }

        return dp[n-1][amount];
    }

    int optimal(vector<int> coins, int amount){

        int n = coins.size();
        vector<int> prev(amount+1, 1e8), cur(amount+1, 1e8);

        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0)
                prev[a] = a / coins[0];
        }

        for(int index=1; index<n; index ++){

            for(int a=0; a<=amount; a++) {

                int not_taken = prev[a];

                int taken = 1e8;
                if(coins[index] <= a)
                    taken = 1 + cur[a-coins[index]];

                cur[a] = min(not_taken, taken);
            }

            prev = cur;
        }

        return prev[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);

        return ans >= 1e8 ? -1 : ans;
    }
};