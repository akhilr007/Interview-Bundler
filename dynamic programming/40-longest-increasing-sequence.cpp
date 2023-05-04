class Solution {
public:
    int solve(int index, int prev_index, vector<int>& nums, vector<vector<int>>& dp){

        if(index >= nums.size())
            return 0;

        if(dp[index][prev_index+1] != -1)
            return dp[index][prev_index+1];

        int notTake = 0 + solve(index+1, prev_index, nums, dp);

        int take = 0;
        if(prev_index == -1 || nums[index] > nums[prev_index])
            take = 1 + solve(index+1, index, nums, dp);

        return dp[index][prev_index+1] = max(notTake, take);
    }

    int tabulation(vector<int>& nums){

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (n+1, 0));

        for(int index=n-1; index>=0; index--){

            for(int prev_index=index-1; prev_index>=-1; prev_index--){

                int notTake = 0 + dp[index+1][prev_index+1];

                if(prev_index == -1 || nums[index] > nums[prev_index])
                    take = 1 + dp[index+1][index+1];

                dp[index][prev_index+1] = max(notTake, take);
            }
        }

        return dp[0][0];
    }

    int optimal(vector<int>& nums){

        int n = nums.size();

        vector<int> ahead(n+1, 0), cur(n+1, 0);

        for(int index=n-1; index>=0; index--){

            for(int prev_index=index-1; prev_index>=-1; prev_index--){

                int notTake = 0 + ahead[prev_index+1];

                if(prev_index == -1 || nums[index] > nums[prev_index])
                    take = 1 + ahead[index+1];

                cur[prev_index+1] = max(notTake, take);
            }
            ahead = cur;
        }
        
        return ahead[0];
    }

    int lis(vector<int>& nums){

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (n+1, -1)); // n+1 due to -1 so used shifting
        return solve(0, -1, nums, dp);
        // f(0, -1) -> give lis from 0 to n-1 
    }
};