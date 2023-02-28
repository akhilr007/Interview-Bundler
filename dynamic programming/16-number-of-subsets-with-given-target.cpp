class Solution{
public:
    // recursion and memoization
    // time complexity 
    // recursion -> O(2^n) space complexity -> O(n)
    // memoization -> O(n * target) space complexity -> O(n) + O(n * target)

    /*
    if nums[i] = 0
    [0, 0, 1] target = 1
    [0, 1], [0, 1], [0, 0, 1], [1]
    if(sum == 0 and sum == arr[0]) return 2;
    if(sum == 0 or sum == arr[0]) return 1;
    else return 0;
    /*/
    int solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp, int n){

        if(target == 0)
            return 1;
        if(idx == 0)
            return nums[0] == target;
        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        int notTake = solve(idx - 1, target, nums, dp, n);
        int take = 0;
        if(nums[idx] <= target)
            take = solve(idx - 1, target - nums[idx], nums, dp, n);

        return dp[idx][target] = notTake + take;
    }

    // time complexity -> O(n * target)
    // space complexity -> O(n * target)
    int solveTab(vector<int>& nums, int target, int n){

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

                dp[i][j] = notTake + take;
            }
        }

        return dp[n-1][target];
    }

    // time complexity -> O(n * target)
    // space complexity -> O(target)
    int numberOfSubset(vector<int> nums, int target, int n){
        
        vector<int> prev(target + 1, 0), cur(target + 1, 0);

        prev[0] = cur[0] = 1;
        
        if(arr[0] <= target)
           prev[arr[0]] = 1;

        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){

                int notTake = prev[j];
                int take = 0;
                if(arr[i] <= j)
                    take = prev[j - arr[i]];

                cur[j] = notTake + take;
            }
            prev = cur;
        }

        return prev[target];
    }
}