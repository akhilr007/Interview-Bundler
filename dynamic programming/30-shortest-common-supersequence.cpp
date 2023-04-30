/*
    s="bleed", t="blue"

    we know to get a string where s and t can be found
    so brute will be ans = "bleedblue"

    to minimise the length, we can include only one char if that char are present
    in both the string

    so length will be = n + m - lcs(s, t)

    then we can obtain the string
*/

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                int ans = 0;
                if(s[i-1] == t[j-1])
                    ans = 1 + dp[i-1][j-1];
                else
                    ans = max(dp[i-1][j], dp[i][j-1]);
                
                dp[i][j] = ans;
            }
        }
        
        int i=n, j=m;
        string ans="";
        
        while(i>0 && j>0){
            
            if(s[i-1] == t[j-1]){
                ans += s[i-1];
                i -= 1;
                j -= 1;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += s[i-1];
                i--;
            }
            else{
                ans += t[j-1];
                j--;
            }
        }
        
        while(i>0){
            ans += s[i-1];
            i--;
        }
        
        while(j>0){
            ans += t[j-1];
            j--;
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};