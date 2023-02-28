class Solution{
public:
    void helper(int idx, vector<int>& arr, int target, vector<int> ans, vector<vector<int>>& res){

        if(target == 0){
            res.push_back(ans);
            return;
        }

        if(idx >= arr.size() || target < 0) return;

        ans.push_back(A[idx]);
        helper(idx+1, arr, target-arr[idx], ans, res);
        ans.pop_back();

        // we can use one element only one time
        while(idx+1 < arr.size() && arr[idx] == arr[idx+1]) idx++;

        helper(idx+1, arr, target, ans, res);
    }

    vector<vector<int>> combinationSum2(vector<vector<int>>& arr, int target){
         
        vector<vector<int>> res;
        vector<int> ans;

        sort(arr.begin(), arr.end()); // in case we need to give ans in sorted order

        helper(0, arr, target, ans, res);
        return res;
    }
};