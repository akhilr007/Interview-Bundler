class Solution{
private:    
    // brute -> O(n!*n) space -> O(n)
    void permute(int idx, vector<int>& nums, vector<int>& permutations, vector<int> ans, int freq[]){

        if(idx >= ans.size()){
            permutations.push_back(ans);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(freq[i] == 0){
                freq[i]=1;
                ans.push_back(nums[i]);
                permute(idx+1, nums, permutations, ans, freq);
                freq[i]=0;
                ans.pop_back();
            }
        }
    }

public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& permutations){

        if(idx>=nums.size()){
            permutations.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            solve(idx+1, nums, permutations);
            swap(nums[idx], nums[i]);
        }
    }
    
    vector<vector<int>> findPermutations(vector<int>& nums){
        int n = nums.size();

        vector<vector<int>> permutations;
        solve(0, nums, permutations);
        return permutations;
    }
};