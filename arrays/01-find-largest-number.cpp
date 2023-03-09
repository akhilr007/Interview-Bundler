class Solution {
public:
    int findLargestNumber(vector<int>& nums, int n){

        int largest=nums[0];
        for(int i=1; i<n; i++){
            largest = max(largest, nums[i]);
        }

        return largest;
    }
};