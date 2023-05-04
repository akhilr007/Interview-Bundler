class Solution{
public:
    void printLIS(vector<int>& nums){

        int n = nums.size();

        vector<int> dp(n, 1);
        // dp[i] -> lis ending at index i

        int maxLength = 0;
        int maxIndex;

        for(int index=0; index<n; index++){

            for(int prev_index=0; prev_index<index; prev_index++){

                if(nums[index] > nums[prev_index]){
                    dp[index] = max(dp[index], 1 + dp[prev_index]);
                }
            }

            if(dp[index] > maxLength){
                maxLength = dp[index];
                maxIndex = index;
            }
        }

        // printing lis logic

        queue<tuple<int, int, string>> q;
        // <lis, index, path_so_far>
        q.push(make_tuple(maxLength, maxIndex, to_string(nums[maxIndex]) + " "));

        while(!q.empty()){

            auto [length, index, psf] = q.front();
            q.pop();

            if(length == 1)
            {
                cout << psf << endl;
            }

            for(int i=0; i<index; i++){
                
                if(dp[i] == length-1 && nums[index] > nums[i]){
                    q.push(make_tuple(dp[i], i, to_string(nums[i]) + " " + psf));
                }
            }
        }
        
    }
};