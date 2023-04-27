class Solution {
public:
    // tc -> O(n * W)
    // sc -> O(n * W) + O(n) -> recursion stack space
    int solve(int index, int W, int wt[], int val[], vector<vector<int>>& dp){

        // base case
        if(index == 0){
            // if weight at 0 th index is less than reqd W return val[0]
            if(wt[0] <= W) return val[0];

            return 0; // if not, then return 0
        }

        if(dp[index][W] != -1)
            return dp[index][W];

        int not_taken = solve(index-1, W, wt, val, dp);

        int taken = 0;
        if(wt[index] <= W)
            taken = val[index] + solve(index-1, W-wt[index], wt, val, dp);

        return dp[index][W] = max(not_taken, taken);
    }

    // tc -> O(n * W)
    // sc -> O(n * W)
    int tabulation(int W, int wt[], int val[], int n){

        vector<vector<int>> dp(n, vector<int> (W+1, 0));

        // base case
        /*
            if(index == 0)
            {
                if(wt[0] <= W) return val[0];
                return 0
            }
        */

        for(int w=wt[0]; w<=W; w++)
            dp[0][w] = val[0];

        for(int index=1; index<n; index++){

            for(int w=0; w<=W; w++) {

                int not_taken = dp[index-1][w];

                int taken = 0;
                if(wt[index] <= w)
                    taken = val[index] + dp[index-1][w-wt[index]];

                dp[index][w] = max(not_taken, taken);
            }
        }

        return dp[n-1][W];
    }

    // tc -> O(n * W)
    // sc -> O(W) + O(W)
    int optimal(int W, int wt[], int val[], int n){

        vector<int> prev(W+1, 0), cur(W+1, 0);

        for(int w=wt[0]; w <= W; w ++)
            prev[w] = val[0];

        for(int index=1; index<n; index++){

            for(int w=0; w <= W; w++){

                int not_taken = prev[w];

                int taken = 0;
                if(wt[index] <= w)
                    taken = val[index] + prev[w-wt[index]];

                cur[w] = max(not_taken, taken);
            }

            prev = cur;
        }

        return prev[W];
    }

    int 01knapsack(int W, int wt[], int val[], int n){

        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return solve(n-1, W, wt, val, dp);
    }
}