class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>> & dp){

        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]){
            int take = solve(i-1, j-1, s, t, dp);
            int notTake = solve(i-1, j, s, t, dp);

            return dp[i][j] = notTake + take;
        }

        return dp[i][j] = solve(i-1, j, s, t, dp);
    }

    int tabulation(string s, string t){

        int n = s.size();
        int m = t.size();

        vector<vector<double>> (n+1, vector<double> (m+1, 0));

        // if(j<0) return 1;
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;

        for(int i=1; i<=n; i++){

            for(int j=0; j<=m; j++){

                if(s[i-1] == t[j-1]){

                    double take = dp[i-1][j-1];
                    double notTake = dp[i-1][j];

                    dp[i][j] = notTake + take;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[n][m]
    }

    int optimal(string s, string t){

        int n = s.size();
        int m = t.size();

        vector<double> prev(m+1, 0), cur(m+1, 0);

        prev[0] = cur[0] = 1; // base case

        for(int i=1; i<=n; i++){

            for(int j=1; j<=m; j++){

                if(s[i-1] == t[j-1]){

                    double take = prev[j-1];
                    double notTake = prev[j];

                    cur[j] = notTake + take;
                }
                else
                    cur[j] = prev[j];
            }

            prev = cur;
        }

        return (int)prev[m]
    }

    int numDistinct(string s, string t){

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
}