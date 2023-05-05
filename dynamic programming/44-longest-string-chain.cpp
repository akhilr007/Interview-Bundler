class Solution {
public:
    bool isStringChain(const string& w1, const string& w2){

        int n = w1.size();
        int m = w2.size();


        if(n != m + 1) return false;

        int i=0, j=0;

        while(i<n){

            if(j<m && w1[i] == w2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return i==n && j==m;
    }

    int longestStringChain(vector<string>& words){

        int n = words.size();

        sort(begin(words), end(words), [](const string& s1, const string& s2){
            return s1.size() < s2.size();
        });

        vector<int> dp(n, 1);

        int maxi = 0;

        for(int index=0; index<n; index++){

            for(int prev_index=0; prev_index<index; prev_index++){

                if(isStringChain(words[index], words[prev_index])){

                    dp[index] = max(dp[index], 1 + dp[prev_index]);
                }
            }

            maxi = max(maxi , dp[index]);
        }

        return maxi;
    }
};