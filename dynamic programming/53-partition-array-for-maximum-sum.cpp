class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp){
        
        if(i == arr.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int len = 0;
        
        for(int j=i; j<min((int)arr.size(), i+k); j++){
            
            len++;
            maxi = max(maxi, arr[j]);
            
            int sum = len * maxi + solve(j+1, arr, k, dp);
            
            ans = max(ans, sum);
        }
        
        return dp[i] = ans;
    }
    
    int tabulation(vector<int>& arr, int k){
        
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            
            int maxi = INT_MIN;
            int ans = INT_MIN;
            int len = 0;

            for(int j=i; j<min(n, i+k); j++){

                len++;
                maxi = max(maxi, arr[j]);

                int sum = len * maxi + dp[j+1];

                ans = max(ans, sum);
            }
            
            dp[i] = ans;
        
        }
        
        return dp[0];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int> dp(arr.size(), -1);
        return solve(0, arr, k);
    }
};