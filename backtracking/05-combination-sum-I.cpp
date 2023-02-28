class Solution{
public:
    void helper(int idx, vector<int>& a, vector<int> ans, vector<vector<int>>& res, int target){

        if(target == 0){
            res.push_back(ans);
            return;
        }

        if(idx >= a.size() || target < 0) return;

        ans.push_back(a[idx]);
        helper(idx, a, ans, res, target - a[idx]);

        ans.pop_back();
        helper(idx+1, a, ans, res, target);
    }
    
    vector<vector<int>> solve(vector<int>& arr, int target){

        // arr can have duplicate elements;
        // to get rid of duplicate elements use set

        vector<vector<int>> res;
        set<int> s(arr.begin(), arr.end());

        vector<int> b(s.begin(), s.end());
        vector<int> ans;
        
        helper(0, b, ans, res, target);
        return res;
    }
};