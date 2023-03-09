class Solution {
public:
    // brute force
    // time complexity -> O(n) and space complexity -> O(n)
    int bruteForce(vector<int>& nums){

        int n = nums.size();

        vector<int> res;
        for(auto &x : nums){
            if(x != 0)
                res.push_back(x);
        }

        int numberOfZeros = n - res.size();
        for(int i=0; i<numberOfZeros; i++){
            res.push_back(0);
        }

        return res;
    }

    // optimal
    // time complexity -> O(n) and space complexity -> O(1)
    void moveZerosToEnd(vector<int>& nums){

        int n = nums.size();

        int j=-1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        if( j == -1)
            return;

        for(int i=j+1; i<n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }

    }
};