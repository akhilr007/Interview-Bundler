class Solution{
public:
    // time complexity -> O(n * target)
    // space complexity -> O(n * target) which can further be optimized to O(target)
    int minPartition(int arr[], int n){

        int total_sum = 0;
        for(int i=0; i<n; i++)
            total_sum += arr[i];
        
        int target = total_sum;

        vector<vector<int>> dp(n, vector<int> (target + 1, 0));
        for(int i=0; i<n; i++)
            dp[i][0] = 1;

        if(arr[0] <= target)
            dp[0][arr[0]] = 1;

        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){

                int notTake = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j)
                    take = dp[i-1][j - arr[i]];

                dp[i][j] = notTake | take;
            }
        }

        int result = INT_MAX;
        for(int i=0; i<=target/2; i++){
            if(dp[n-1][i] == 1){
                int s1 = i;
                int s2 = total_sum - s1;

                result = min(result, abs(s1 - s2));
            }
        }

        return result;
    }
};