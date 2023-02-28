class Solution{
public:
    bool subsetSum(vector<int>& nums, int target, int n){

        vector<int> prev(target+1, 0), cur(target+1, 0);

        prev[0] = cur[0] = 1;
        if(nums[0] <= target) 
            prev[nums[0]] = 1;

        for(int i=1; i<n; i++){

            for(int j=1; j<=target; j++){

                int notPick = prev[j];
                int pick = 0;
                if(nums[i] <= j)
                    pick = prev[j - nums[i]];
                
                cur[j] = notPick | pick;
            }

            prev = cur;
        }

        return prev[target];
    }

    bool canPartition(vector<int>& nums){

        // an array can be divide into two equal subsets if they have total_sum which is even
        int n = nums.size();
        int totalSum = 0;

        for(auto num: nums)
            totalSum += num;
        
        if(totalSum % 2)
            return false;

        int target = totalSum / 2 ;

        return subsetSum(nums, target, n);
    }
};