class Solution {
public:
    int longestBitonicSubsequence(vector<int>& nums){

        int n = nums.size();

        // lis from left
        vector<int> dp1(n, 1);

        for(int index=0; index<n; index++){

            for(int prev_index=0; prev_index<index; prev_index++){

                if(nums[index] > nums[prev_index]){

                    dp1[index] = max(dp1[index], 1 + dp1[prev_index]);
                }
            }
        }

        // lis from right
        vector<int> dp2(n, 1);

        for(int index=n-1; index>=0; index--){

            for(int prev_index=n-1; prev_index>index; prev_index--){

                if(nums[index] > nums[prev_index]){

                    dp2[index] = max(dp2[index], 1 + dp2[prev_index]);
                }
            }
        }

        int result = 0;

        for(int index=0; index<n; index++){

            result = max(result, dp1[index] + dp2[index] - 1);
        }
        return result;
    }
};