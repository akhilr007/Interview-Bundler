class Solution{
public:
    // time complexity -> O(2^n)
    // space complexity -> O(n)
    int solveRec(int idx, vector<int>& nums){

        if(idx < 0) return 0;
        if(idx == 0) return nums[idx];

        int notPick = 0 + solveRec(idx - 1, nums);
        int pick = nums[idx] + solve(idx - 2, nums);

        return max(notPick, pick);
    }

    // time complexity -> O(n)
    // space complexity -> O(n + n)
    int t[n] = {-1};
    int solveMem(int idx, vector<int>& nums){

        if(idx < 0) return 0;
        if(idx == 0) return nums[idx];
        if(t[idx] != -1) return t[idx];

        int notPick = 0 + solveMem(idx - 1, nums);
        int pick = nums[idx] + solveMem(idx - 2, nums);

        return t[idx] = max(notPick, pick);
    }

    // time complexity -> O(n)
    // space complexity -> O(n)
    int solveTab(vector<int>& nums, int n){

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for(int i=1; i<n; i++){

            int notPick = 0 + dp[i-1];
            int pick = nums[i];
            if(i >= 2) pick = nums[i] + dp[i-2];

            dp[i] = max(notPick, pick);
        }

        return max(dp[n-1], dp[n-2]);
    }

    // time complexity -> O(n)
    // space complexity -> O(1)
    int maxSumNonAdjacentElements(vector<int>& nums, int n){

        int prev = nums[0]; // dp[i-1]
        int prev2 = 0; // dp[i-2]

        for(int i=1; i<n; i++){

            int notPick = 0 + prev;
            int pick = nums[i];
            if(i >= 2) pick = pick + prev;

            int cur = max(notPick, pick);
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
}