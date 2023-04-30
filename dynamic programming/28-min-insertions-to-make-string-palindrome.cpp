/*
approach:
1. if we reverse the string, and append the reverse string at the end it will make
the string palindrome.
string s = abcaa , r = aacba
string ans = abcbaaacba // it is palindrome

so max insertion to make a string palindrome is n (length of string)

so to minimise it, we can intact the longest palindrome subsequence in a string
lika aaa, aba, aca (any of them as all are equal length)

so 2 chars are left and if we reverse them and add it to string it becomes 
palindrome

so ans is min_insertions = n - find LPS(s, r)
*/

class Solution {
public:
    int findLongestPalindromicSubsequence(string s, string r){

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

    int minInsertions(string s){

        int n = s.size();
        string r = s;
        reverse(begin(r), end(r));

        return n - findLongestPalindromicSubsequence(s, r);
    }
};