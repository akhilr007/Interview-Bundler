class Solution{
public:
    int numberOfSubsetsWithGivenTarget(int idx, vector<int>& arr, int target,
    vector<vector<int>>& dp){

        if(idx == 0){
            if(target == 0 && arr[0] == 0)
                return 2; // 2 ways 
            else if(arr[0] == target || target == 0)
                return 1;
            else    
                return 0;
        }
        if(dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = numberOfSubsetsWithGivenTarget(idx - 1, arr, target, dp);
        int take = 0;
        if(arr[idx] <= target)
            take = numberOfSubsetsWithGivenTarget(idx - 1, arr, target - arr[idx], dp);

        return dp[idx][target] = notTake + take;
    }

    int countPartitions(int n, int d, vector<int>& arr){

        int totalSum = 0;
        for(auto &it : arr) totalSum += it;

        if(totalSum - d < 0 or (totalSum - d) % 2 ) return 0;

        vector<vector<int>> dp(n, vector<int> (totalSum + 1, -1));
        return numberOfSubsetsWithGivenTarget(n-1, arr, target, dp);
    }
}

int countSubset(vector<int>& arr, int target){
    
    int mod = (int)1e9+7;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target + 1, 0));
    
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    
    if(arr[0] != 0 and arr[0] <= target)
        dp[0][arr[0]] = 1;
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=target; j++){
            
            int notTake = dp[i-1][j];
            int take = 0;
            if(arr[i] <= j)
                take = dp[i-1][j - arr[i]];
             
            dp[i][j] = (notTake + take) % mod;
        }
    }
    
    return dp[n-1][target];
}

int countPartitions(int n, int d, vector<int> &arr) {
    
    int total_sum = 0;
    for(auto &it : arr)
        total_sum += it;
    
    if(total_sum - d<0 or (total_sum - d) % 2)
        return 0;
    
    return countSubset(arr, (total_sum-d) / 2);
}