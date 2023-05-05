class Solution {
public:
    // tc -> O(n^2) * n -> O(n^3)
    // sc -> O(n^2) + O(n)
    int solve(int i, int j, int arr[], vector<vector<int>>& dp){

        if(i == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;
        // we can partition from i to j-1 such that f(i, k) and f(k+1, j)
        for(int k=i; k<j; k++){

            int operations = arr[i-1] * arr[k] * arr[j];
            int steps = operations * solve(i, k, arr, mini) + solve(k+1, j, arr, mini);

            mini = min(mini, steps); 
        }

        return dp[i][j] = mini;
    }

    int tabulation(int N, int arr[]){

        int dp[N][N];

        // base case -> i==j return 0
        for(int i=0; i<N; i++)
            dp[i][i] = 0;

        // (1 -> j) in recursion
        for(int i=N-1; i>=1; i--){

            for(int j=i+1; j<N; j++){

                int mini = 1e9;

                for(int k=i; k<j; k++){

                    int operations = arr[i-1] * arr[k] * arr[j];
                    int steps = operations + dp[i][k] + dp[k+1][j];

                    mini = min(mini, steps);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][N-1];
    }

    int matrixChainMultiplication(int N, int arr[]){

        vector<vector<int>> dp(N, vector<int> (N, -1));
        return solve(1, N-1, arr, dp);
        // f(i, j) -> min operation to multiply from i to j for eg :- (ABCD)
    }
};