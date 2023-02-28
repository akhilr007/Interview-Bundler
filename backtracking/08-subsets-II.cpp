class Solution{
public:
    void helper(int idx, vector<int>& arr, vector<int> ans, vector<vector<int>>& res){

        if(idx >= arr.size()){
            res.push_back(ans);
            return;
        }

        ans.push_back(arr[idx]);
        helper(idx+1, arr, ans, res);
        ans.pop_back();

        while(idx+1 < arr.size() && arr[idx] == arr[idx+1]) idx++;

        helper(idx+1, arr, ans, res);
    }
    
    vector<vector<int>> subset2(vector<vector<int>>& arr){

        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        vector<int> ans;

        helper(0, arr, ans, res);
        sort(res.begin(), res.end());

        return res;
    }
}