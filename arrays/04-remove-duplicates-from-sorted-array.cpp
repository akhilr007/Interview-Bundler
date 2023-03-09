class Solution {
public:

    // time complexity -> O(nlogn + n) space complexity -> O(n)
    int bruteForce(vector<int>& nums){

        int n = nums.size();
        set<int> st;

        for(auto &x: nums)
            st.insert(x);
        
        int k = st.size();
        int j=0;

        for(auto &x : st){
            nums[j++] = x;
        }

        return k;
    }

    // time complexity -> O(n)
    int removeDuplicates(vector<int>& nums){

        int n = nums.size();

        int j=0;
        for(int i=1; i<n; i++){

            if(arr[i] != arr[j]){
                arr[++j] = arr[i];
            }
        }

        return j+1;
    }
};