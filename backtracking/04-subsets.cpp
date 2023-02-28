class Solution{
public:

    void helper(int idx. vector<int>& arr, vector<vector<int>>& ans, vector<int> res){

        if(idx >= arr.size()){
            ans.push_back(res);
            return res;
        }

        res.push_back(arr[idx]);
        helper(idx+1, arr, ans, res);

        res.pop_back();
        helper(idx+1, arr, ans, res);

    }
    
    vector<vector<int>> subset(vector<int>& arr){

        vector<vector<int>> ans;
        vector<int> res;
        sort(arr.begin(), arr.end());

        helper(0, arr, ans, res);
        sort(ans.begin(), ans.end());

        return ans;
    }
}