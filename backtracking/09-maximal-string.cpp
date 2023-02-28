class Solution {
private:
    // time complexity -> O(n*n)^k space complexity -> O(n)
    void bruteForce(string str, string res, int k){
        
        if(stoi(str) > stoi(res)) res = str;

        if(k == 0) return;

        for(int i=0; i<str.length()-1; i++){
            for(int j=i+1; j<str.length(); j++){
                if(str[j] > str[i]){
                    swap(str[i], str[j]);
                    helper(str, res, k-1);
                    swap(str[i], str[j]);
                }
            }   
        }
    }

public:
    // time complexity -> O(n^k) space complexity -> O(n)
    void solve(int index, string str, string& res, int n, int k){

        if(k == 0 || index == n) return;

        char maxChar = str[index];
        // find max char in right after index
        for(int j=index+1; j<n; j++){
            if(str[j] > maxChar) maxChar = str[j];
        }

        if(maxChar != str[index]) k--; 

        for(int j=n-1; j>index; j--){
            
            if(str[j] == maxChar){

                swap(str[index], str[j]);
                if(str > res) res = str;

                solve(index+1, str, res, n, k);

                swap(str[index], str[j]);
            }
        }
    }

    string maximalString(string str, int k){
        string res = ans;
        int n = str.length();
        solve(0, str, res, n, k);
        return res;
    }
};