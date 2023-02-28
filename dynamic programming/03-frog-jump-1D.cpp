class Solution{
private:
    // time complexity -> O(2^n)
    // space complexity -> O(n)
    int solveRec(int idx, vector<int>& height, int n){

        if(idx == 0) return 0;

        int left = solveRec(idx-1, height, n) + abs(height[idx] - height[idx - 1]);

        int right = 1e8;
        if(idx > 1) right = solveRec(idx - 2, height, n) + abs(height[idx] - height[idx - 2]);

        return min(left, right);
    }

    // time complexity -> O(n)
    // space complexity -> O(n + n)
    int solveMem(int idx, vector<int>& height, int n){

        // t[n+1] = {-1}
        if(idx == 0) return 0;
        if(t[idx] != -1) return t[idx];

        int left = solveMem(idx-1, height, n) + abs(height[idx] - height[idx - 1]);

        int right = 1e8;
        if(idx > 1) right = solveMem(idx - 2, height, n) + abs(height[idx] - height[idx - 2]);

        return t[idx] =  min(left, right);
    }

    // time complexity -> O(n)
    // space complexity -> O(n)
    int solveTab(int n){

        vector<int> dp(n, 0);

        for(int i=1; i<n; i++){

            int left = dp[i-1] + abs(height[i] - height[i-1]);
            int right = 1e8;
            if(i > 1) right = dp[i-2] + abs(height[i] - height[i-2]);

            dp[i] = min(left, right);
        }

        return dp[n-1];
    }

public:
    // time complexity -> O(n)
    // space complexity -> O(1)
    int frogJump(vector<int>& height, int n){

        int firstPrev = 0 ; // dp[i-1]
        int secondPrev = 0; // dp[i-2]

        for(int i=1; i<n; i++){

            int left = firstPrev + abs(height[i] - height[i-1]);
            int right = 1e8;
            if(i > 1) right = secondPrev + abs(height[i] - height[i-2]);

            int cur = min(left, right);
            secondPrev = firstPrev;
            firstPrev = cur;
        }

        return firstPrev;
    }   
};