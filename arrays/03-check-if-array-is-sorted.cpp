class Solution {
public:
    int isSorted(vector<int>& nums, int n){

        for(int i=1; i<n; i++){

            if(nums[i-1] > nums[i])
                return false;
        }

        return true;
    }
};