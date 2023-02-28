class Solution {
private:
    // time complexity -> O(2^n)
    // space complexity -> O(n)
    int solveRec(int n){

        if(n == 1 or n == 2) return 1;

        int oneStep = solveRec(n-1);
        int twoStep = solveRec(n-2);

        return oneStep + twoStep;
    }

    // time complexity -> O(n)
    // space complexity -> O(n for t and n for recursion stack)
    int solveMem(int n){

        // int t[n+1] = {-1}
        if(n == 1 or n == 2) return 1;
        if(t[n] != -1) return t[n];

        int oneStep = solveMem(n-1);
        int twoStep = solveMem(n-2);

        return t[n] = oneStep + twoStep;
    }

    // time complexity -> O(n)
    // space complexity -> O(n)
    int solveTab(int n){

        if(n == 1 or n == 2) return n;

        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

public: 
    // time complexity -> O(n)
    // space complexity -> O(1)
    int climbStairs(int n){

        if(n == 1 or n == 2) return 1;

        int first = 1;
        int second = 2;

        for(int i=3; i<=n; i++){

            int temp = first + second;
            first = second;
            second = temp;
        }

        return second;
    }
};