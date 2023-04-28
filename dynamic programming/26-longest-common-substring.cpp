class Solution {
public:
    int optimal(string s, string t){

        int n = s.size();
        int m = t.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);
        int ans=0;

        for(int i=1; i<=n; i++){

            for(int j=1; j<=m; j++){

                if(s[i-1] == t[j-1]){
                    cur[j] = 1 + prev[j-1];
                    ans = max(ans, cur[j]);
                }
                else cur[j] = 0;
            }
            prev = cur;
        }

        return ans;
    }

    int longestCommonSubstring(string s, string t){

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int ans=0;

        for(int i=1; i<=n; i++){

            for(int j=1; j<=m; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    // here if the sequence breaks we will not consider
                    // it, because in substring consecutive characters
                    // are must, so we put 0
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
}