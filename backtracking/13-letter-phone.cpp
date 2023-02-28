class Solution{
public:
    void dfs(int i, string cur_string, string& digits, string digitMapping[], vector<string>& ans){
        if(cur_string.length() == digits.length()){
            ans.push_back(cur_string);
            return;
        }

        string stringCodeFromDigit = digitMapping[digits[i]-'0'];
        for(char c: stringCodeFromDigit){
            dfs(i+1, cur_string+c, digits, digitMapping, ans);
        }
    }
    
    vector<string> letterCombinations(string& digits){

        vector<string> ans;
        if(digit.length() == 0) return ans;

        string digitMapping[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(0, "", digits, digitMapping, ans);

        return ans;
    }
};