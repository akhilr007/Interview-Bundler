class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){

        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<int> dp(n, 1);

        int maxLength = 0;
        int maxIndex;

        for(int index=0; index<n; index++){

            for(int prev_index=0; prev_index<index; prev_index++){

                if(nums[index] % nums[prev_index] == 0){

                    dp[index] = max(dp[index], 1 + dp[prev_index]);
                }
            }

            if(dp[index] > maxLength){
                maxLength = dp[index];
                maxIndex = index;
            }
        }

        vector<int> result;

        queue< pair<int, int> > q;
        q.push({maxLength, maxIndex});

        result.push_back(nums[maxIndex]);

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int length = node.first;
            int index = node.second;

            if(length == 1){
                break;
            }

            for(int i=0; i<index; i++){

                if(dp[i] == length-1 && (nums[index] % nums[i] == 0)){

                    result.push_back(nums[i]);
                    q.push({dp[i], i});

                    break;
                }
            }
        }

        return result;
    }
};