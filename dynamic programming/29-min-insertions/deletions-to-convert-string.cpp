/*
 s1 = "leetcode", s2="etco"

 to make both string equal 

 1. find longest common subsequence b/w them
 2. no ans will be n-lcs + m-lcs
*/

class Solution{
public:
    int findLCS(string s1, string s2){

        int n = s.size();

        vector<int> prev(n+1, 0), cur(n+1, 0);

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){

                int ans=0;
                if(s[i-1] == r[j-1])
                    ans = 1 + prev[j-1];
                else
                    ans = max(prev[j], cur[j-1]);

                cur[j] = ans;
            }
            prev = cur;
        }

        return prev[n];
    }
    
    int minDeletion(string s1, string s2){

        int n = s1.size();
        int m = s2.size();

        int lcs = findLCS(s1, s2);

        return n-lcs + m-lcs;
    }
};