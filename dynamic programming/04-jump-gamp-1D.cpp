class Solution{
public:
    // time complexity -> O(k ^ n)
    // space complexity -> O(n)
    int solveRec(int idx, vector<int>& nums, int n){

        if(idx >= n-1) return true;

        for(int j=1; j<=nums[idx]; j++){

            if(solveRec(idx + j, nums, n) == true) return true;
        }

        return false;
    }


    // time complexity -> O(k * n)
    // space complexity -> O(n)
    int t[100001] = {-1};
    int solveMem(int idx, vector<int>& nums, int n){

        if(idx >= n-1) return true;
        if(t[idx] != -1) return t[idx];

        for(int j=1; j<=nums[idx]; j++){

            if(solveMem(idx + j, nums, n) == true) return t[idx] = true;
        }

        return t[idx] = false;
    }

    // time complexity -> O(k * n)
    // space complexity -> O(n)
    int solveTab(vector<int>& nums, int n){

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i=1; i<n; i++){

            for(int j=i-1; j>=0; j--){

                if(dp[j] == 1 && j + nums[j] >= i) {

                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n-1];
    }

    // most optimal solution
    // time complexity -> O(n)
    // space complexity -> O(1)
    int canJump(vector<int> nums, int n){

        int maxReachable = 0;

        for(int i=0; i<n; i++){

            if(i > maxReachable) return false;
            
            maxReachable = max(maxReachable, i + nums[i]);
       }

       return true;
    }
};