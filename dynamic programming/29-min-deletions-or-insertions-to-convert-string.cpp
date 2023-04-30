/**
s1 = "leetcode", s2="etco"

1. find lcs , lcs = etco 
2. n - lcs + m - lcs
*/

class Solution{
public:
    int findLCS(string s1, string s2){

        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                int ans=0;
                if(s1[i-1] == s2[j-1])
                    ans = 1 + prev[j-1];
                else
                    ans = max(prev[j], cur[j-1]);

                cur[j] = ans;
            }

            prev = cur;
        }

        return prev[m];
    }

    int minDeletion(string s1 , string s2){

        int n = s1.size();
        int m = s2.size();

        int lcs = findLCS(s1, s2);

        return n-lcs + m-lcs;
    }
};