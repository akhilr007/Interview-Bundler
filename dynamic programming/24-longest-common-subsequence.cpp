class Solution {
public:
    // tc -> O(n*m)
    // sc -> O(n*m) + O(n+m) {recursion stack space}
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){

        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s[i] == t[j])
            ans = 1 + solve(i-1, j-1, s, t, dp);
        else
            ans = max(solve(i-1, j, s, t, dp), solve(i, j-1, s, t, dp));

        return dp[i][j] = ans;
    }

    // tc -> O(n*m)
    // sc -> O(n*m)
    int tabulation(string s, string t){

        int n = s.size();
        int t = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }

    // tc -> O(n*m)
    // sc -> O(2m)
    int optimal(string s, string t){

        int n = s.size();
        int t = t.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                int ans = 0;
                if(s[i-1] == t[j-1]){
                    ans = 1 + prev[j-1];
                }
                else{
                    ans = max(prev[j], cur[j-1]);
                }

                cur[j] = ans;
            }

            prev = cur;
        }

        return prev[m];
    }

    int longestCommonSubsequence(string& s, string& t){

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};