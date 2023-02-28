// arr = ["ab", "cd"] -> output -> ["ac". "ad", "bc", "bd"];

class Solution{
public:
    void helper(int idx, vector<string>& arr, vector<string>& ans, string str){

        if(idx >= arr.size()){
            ans.push_back(str);
            return;
        }

        for(int i=0; i<arr[idx].length(); i++){
            char ch = arr[idx][i];
            // append the char
            str += ch;

            helper(idx+1, arr, ans, str);

            // remove the appended char
            str.pop_back();
        }
    }

    vector<string> allPossibleCombinations(vector<string>& arr){

        vector<string> ans;
        helper(0, arr, ans, "");
        // we need lexicographically order
        sort(ans.begin(), ans.end());
        return ans;
    }
};