class Solution{   
private:
    // time complexity -> O(2^n)
    // space complexity -> O(n)
    bool utilRec(int idx, int target, vector<int>& arr){

        if(target == 0)
            return true;
        if(idx == 0)
            return arr[idx] == target;
        
        bool notPick = utilRec(idx - 1, target, arr);
        bool pick = false;
        if(arr[idx] <= target)
            pick = utilRec(idx - 1, target - arr[idx], target);

        return notPick | pick;
    }

    // time complexity -> O(n * target)
    // space complexity -> O(n) + O(n * target)
    int t[n][target+1];
    memset(t, -1, sizeof t);
    bool utilRec(int idx, int target, vector<int>& arr){

        if(target == 0)
            return true;
        if(idx == 0)
            return arr[idx] == target;
        if(t[idx][target] != -1)
            return t[idx][target];
        
        bool notPick = utilRec(idx - 1, target, arr);
        bool pick = false;
        if(arr[idx] <= target)
            pick = utilRec(idx - 1, target - arr[idx], target);

        return t[idx][target] = notPick | pick;
    }

    // time complexity -> O(n * target)
    // space complexity -> O(n * target)
    bool utilTab(vector<int>& arr, int target){

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1, 0)); 

        // target == 0 return true;
        for(int i=0; i<n; i++)
            dp[i][0] = 1;
        
        // idx == 0 -> then dp[0][arr[0]] = true
        if(arr[0] <= target)
            dp[0][arr[0]] = 1;

        for(int i=1; i<n; i++){

            for(int j=1; j<=target; j++){

                int notPick = dp[i-1][j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = dp[i-1][j - arr[i]];
                
                dp[i][j] = notPick | pick;
            }
        }

        return dp[n-1][target];
    }

public:
    // time complexity -> O(n * target)
    // space complexity -> O(target)
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n = arr.size();
        vector<int> prev(target+1), cur(target+1, 0); 

        // target == 0 return true;
        prev[0] = cur[0] = 1;
        
        // idx == 0 -> then dp[0][arr[0]] = true
        if(arr[0] <= target)
            prev[arr[0]] = 1;

        for(int i=1; i<n; i++){

            for(int j=1; j<=target; j++){

                int notPick = prev[j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = prev[j - arr[i]];
                
                cur[j] = notPick | pick;
            }
            prev = cur;
        }

        return prev[target];
    }
};