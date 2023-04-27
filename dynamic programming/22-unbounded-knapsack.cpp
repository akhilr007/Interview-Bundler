class Solution {
public:
    int solve(int index, int W, int wt[], int val[], vector<vector<int>>& dp){

        if(index == 0){

            if(wt[0] <= W)
                return (W / wt[0]) * val[0];

            return 0;
        }

        if(dp[index][W] != -1)
            return dp[index][W];

        int not_taken = solve(index-1, W, wt, val, dp);

        int taken = 0;
        if(wt[index] <= W)
            taken = val[index] + solve(index, W-wt[index], wt, val, dp);

        return dp[index][W] = max(not_taken, taken);
    }

    int tabulation(int n, int wt[], int val[], int W){

        vector<vector<int>> dp(n, vector<int> (W+1, 0));

        for(int w=wt[0]; w<=W; w++){

            dp[0][w] = (int)(w / wt[0]) * val[0];
        }

        for(int index=1; index<n; index++){

            for(int w=0; w<=W; w++){

                int not_taken = dp[index-1][w];

                int taken = 0;
                if(wt[index] <= w)
                    taken = val[index] + dp[index][w-wt[index]];

                dp[index][w] = max(not_taken, taken);
            }
        }

        return dp[n-1][W];
    }

    int optimal(int n, int wt[], int val[], int W){

        vector<int> prev(W+1, 0), cur(W+1, 0);

        for(int w=wt[0]; w<=W; w++){

            prev[w] = (int)(w / wt[0]) * val[0];
        }

        for(int index=1; index<n; index++){

            for(int w=0; w<=W; w++){

                int not_taken = prev[w];

                int taken = 0;
                if(wt[index] <= w)
                    taken = val[index] + cur[w-wt[index]];

                cur[w] = max(not_taken, taken);
            }
        }

        return prev[W];
    }

    int unboundedKnapsack(int wt[], int val[], int n, int W){

        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return solve(n-1, W, wt, val);
    }
};