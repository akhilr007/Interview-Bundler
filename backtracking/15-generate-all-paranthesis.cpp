class Solution{
public:
// time complexity -> O(2^n) space complexity -> O(n)
    void backtrack(int open, int close, vector<string>& ans, string p){
        if(open == 0 and close ==0){
            ans.push_back(p);
            return;
        }

        if(open != 0) backtrack(open-1, close, ans, p+"(");
        if(close>open) backtrack(open, close-1, ans, p+")");
    }

    vector<string> generateParenthesis(int n){
        vector<string> ans;
        if(n == 0) return ans;

        int open=n, close=n;
        backtrack(open, close, ans, "");
        return ans;
    }
};