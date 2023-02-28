class Solution{
public:
    void helper(int curNumber, int n, int k, vector<int> ans, vector<vector<int>>& res){

        if(k == 0){
            res.push_back(ans);
            return;
        }

        if(curNumber > n) return;

        ans.push_back(curNumber);
        helper(curNumber+1, n, k-1, ans, res);
        ans.pop_back();

        helper(curNumber+1, n, k, ans, res);
    }
    
    vector<vector<int>> combinations(int n, int k){

        int curNumber=1;
        vector<vector<int>> res;
        vector<int> ans;

        helper(curNumber, n, k, ans, res);
        return res;
    }
}