class Solution{
private:
    // time complexity -> O(2^n)
    // space complexity -> O(n) for stack space
    int solveRec(int n){

        if(n == 1 or n == 0) return 0;

        return solveRec(n-1) + solveRec(n-2);
    }

    int t[n+1];
    memset(t, -1, sizeof t);

    // time complexity -> O(n)
    // space complexity -> O(n for recursion stack + n for t)
    int solveMem(int n){

        if(n == 1 or n == 0) return n;
        if(t[n] != -1) return t[n];

        return t[n] = solveMem(n-1) + solveMem(n-2);
    }

    // time complexity -> O(n)
    // space complexity -> O(n)
    int solveTab(int n){

        vector<int> dp(n+1, 0);
        if(n == 0 || n == 1) return n;
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

public: 

    // time complexity -> O(n)
    // space complexity -> O(1)
    int fib(int n){

        int firstNum = 0;
        int secondNum = 1;

        for(int i=2; i<=n; i++){
            int thirdNum = firstNum + secondNum;
            firstNum = secondNum;
            secondNum = thirdNum;
        }

        return secondNum;
    }
};