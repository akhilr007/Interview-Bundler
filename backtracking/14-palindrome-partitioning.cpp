class Solution{
public:
// time complexity -> O(n*(2^n))
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }

        return true;
    }

    void dfs(int idx, string s, vector<string> path, vector<vector<string>>& ans){
        if(idx >= s.length()){
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i-idx+1));
                dfs(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> palindromePartitioning(string s){

        vector<vector<string>> ans;
        vector<string> path;

        dfs(0, s, path, ans);
        return ans;
    }
}