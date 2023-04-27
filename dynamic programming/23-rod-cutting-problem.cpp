class Solution {
public:
    int solve(int index, int length, int price[], vector<vector<int>>& dp){

        if(index == 0){
            return length * price[0];
        }

        if(dp[index][length] != -1)
            return dp[index][length];

        int not_taken = solve(index-1, length, price, dp);

        int taken = 0;
        int rodLength = index+1;
        
        if(rodLength <= length)
            taken = price[index] + solve(index-1, length-rodLength, price, dp);

        return dp[index][length] = max(not_taken, taken);
    }

    int tabulation(int n, int price[]){

        vector<vector<int>> dp(n, vector<int> (n+1, 0));

        for(int length=0; length<=n; length++)
        {
            dp[0][length] = length * price[0];
        }

        for(int index=1; index<n; index++){

            for(int length=0; length <= n; length++){

                int not_taken = dp[index-1][length];

                int taken = 0;
                int rodLength = index+1;

                if(rodLength <= length)
                    taken = price[index] + dp[index][length-rodLength];

                dp[index][length] = max(not_taken, taken);
            }
        }

        return dp[n-1][n];
    }

    int optimal(int n, int price[]){

        vector<int> prev(n+1, 0), cur(n+1, 0);

        for(int length=0; length<=n; length++)
        {
            prev[length] = length * price[0];
        }

        for(int index=1; index<n; index++){

            for(int length=0; length <= n; length++){

                int not_taken = prev[length];

                int taken = 0;
                int rodLength = index+1;

                if(rodLength <= length)
                    taken = price[index] + cur[length-rodLength];

                cur[length] = max(not_taken, taken);
            }

            prev = cur;
        }

        return prev[n];
    }

    int rodCutting(int n, int price[]){

        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return (n-1, n, price, dp);
    }
}