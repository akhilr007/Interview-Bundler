class Solution {
public:
    int usingTraditionalLIS(vector<vector<int>>& envelopes){

        int n = envelopes.size();

        sort(begin(envelopes), end(envelopes));

        vector<int> dp(n, 1);
        int maxi = 0;

        for(int index=0; index<n; index++){

            for(int prev_index=0; prev_index<index; prev_index++){

                if(envelopes[index][0] > envelopes[prev_index][0] &&
                envelopes[index][1] > envelopes[prev_index][1]){

                    dp[index] = max(dp[index], 1 + dp[prev_index]);
                }
            }

            maxi = max(maxi, dp[index]);
        }

        return maxi;
    }

    int usingBinarySearchLIS(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        // sort it wrt columns when rows are equal
        sort(begin(envelopes), end(envelopes), [](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> heights;
        heights.push_back(envelopes[0][1]);

        for(int index=1; index<n; index++){

            int w = envelopes[index][0];
            int h = envelopes[index][1];

            if(h > heights.back()){
                heights.push_back(h);
            }
            else{
                int i = lower_bound(begin(heights), end(heights), h) - begin(heights);
                heights[i] = h;
            }
        }

        return heights.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes){

        return usingBinarySearchLIS(envelopes);
    }
};