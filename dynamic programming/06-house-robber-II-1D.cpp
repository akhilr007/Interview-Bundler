class Solution {
public:
	int helper(vector<int>& nums){

		int n = nums.size();
		int prev = nums[0]; // dp[i-1]
		int prev2 = 0; // dp[i-2]

		for(int i=1; i<n; i++){

			int notPick = 0 + prev;
			int pick = nums[i];
			if(i >= 2) pick = pick + prev2;

			int cur = max(pick, notPick);
			prev2 = prev;
			prev = cur;
		}

		return prev;
	}

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
        	return nums[0];
        
        vector<int> temp1, temp2;

        // first and last element cant be in the answer
        // so in one array, remove the first element and in another remove the last element
        for(int i=0; i<n; i++){

        	if(i != 0) temp1.push_back(nums[i]);
        	if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1), helper(temp2));
    }
};