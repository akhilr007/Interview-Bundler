class Solution {
public:
    // tc -> O(n logn)
    // sc -> O(n)
    int lis(vector<int>& nums){

        int n = nums.size();

        /*
            here, temp does not hold lis
            we are replicating the space used by lis

            nums = [0,1,0,3,2,3]

            we start with temp = [0]

            now for i=1, here 1 > temp.back(), so we can add 1 to last of temp

            temp = [0, 1]

            now for i=2, here 0 !> temp.back(), so we look for index where it is just equal or greater than 0
            using lower_bound and overwrite 0 to that index

            temp = [0, 1]

            now for i=3, 3 > temp.back()
            temp = [0, 1, 3]

            now for i=4, 2 < temp.back()
            lower_bound for 2, will be 3 at index 2

            so, temp = [0, 1, 2]

            now for i=5, 3 > temp.back()
            temp = [0, 1, 2, 3] which gives the size of lis
        */

        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=1; i<n; i++){

            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int index = lower_bound(begin(temp), end(temp), nums[i]) - begin(temp);
                temp[index] = nums[i];
            }
        }

        return temp.size();
    }
};