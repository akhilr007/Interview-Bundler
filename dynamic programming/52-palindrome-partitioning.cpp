class Solution {
public:
    bool isPalindrome(int i, int j, string& s){

        while(i<j){
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(int i, int n, string& s, vector<int>& dp){

        if(i == n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int min_cuts = 1e9;

        for(int j=i; j<n; j++){

            if(isPalindrome(i, j, s)){
                int cost = 1 + solve(j+1, n, s, dp);
                min_cuts = min(min_cuts, cost);
            }
        }

        return dp[i] = min_cuts;
    }

    int tabulation(string s){

        int n = s.size();

        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){

            int min_cuts = 1e9;

            for(int j=i; j<n; j++){

                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1];
                    min_cuts = min(min_cuts, cost);
                }
            }

            dp[i] = min_cuts;
        }

        return dp[0] - 1;
    }

    int palindromePartitioning(string s){

        int n = s.size();

        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1 ; // subtract -1 from solution because at the end we are making 1 partition extra
    }
};