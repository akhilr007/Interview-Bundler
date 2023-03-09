class Solution {
public:
    // brute force
    // O(n) for time and O(n) for space
    void bruteForce(vector<int>& nums, int k){

        int n = nums.size();

        k = k % n;

        int temp[k];
        for(int i=0; i<k; i++){
            temp[i] = nums[i];
        }

        for(int i=k; i<n; i++){
            nums[i-k] = nums[i];
        }

        for(int i=n-k; i<n; i++){
            nums[i] = temp[i-(n-k)];
        }
    }

    // optimal
    // O(n) for time and O(1) for extra space
    int leftRotateByK(vector<int>& nums, int n){

        k = k % n;

        reverse(0, nums.begin() + k);
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};