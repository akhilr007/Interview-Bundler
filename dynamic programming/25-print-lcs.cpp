class Solution {
public:
    string printLCS(string s, string t){

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

        string result;
        int i=n;
        int j=m;

        while(i>0 && j>0)
        {   
            // agar char same hai
            // to hum upward diagonal ke taraf jaa rahe hai
            if(s[i-1] == t[j-1])
            {
                result.push_back(s[i-1]);
                i = i-1;
                j = j-1;
            }
            // agar nai h
            // to max jaha se mil raha hai, waha jaa rahe hai
            else if(dp[i-1][j] > dp[i][j-1])
            {
                i = i-1;
            }
            else
            {
                j = j-1;
            }
        }

        return result;
    }
};