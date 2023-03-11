class Solution {
public:
    // time complexity -> O(n2) space complexity -> O(1)
    int bruteForce(vector<int>& nums){
        
        int n = nums.size();
        for(int i=0; i<=n; i++){
            
            int flag = 0;
            for(int j=0; j<n; j++){
                
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
                return i;
        }
        
        return -1;
    }
    
    // time complexity -> O(n) space complexity -> O(n)
    int better(vector<int>& nums){
        
        int n = nums.size();
        vector<int> hashNums(n+1, 0);
        
        for(int i=0; i<n; i++)
            hashNums[nums[i]]++;
        
        for(int i=0; i<=n; i++){
            
            if(hashNums[i] == 0)
                return i;
        }
        
        return -1;
    }
    
    // time complexity -> O(n) space complexity -> O(1)
    // can be problematic if n is 10^5 we have to store it in long long
    int optimal1(vector<int>& nums){
        
        int n = nums.size();
        
        int totalSum = 0;
        totalSum = (n * (n+1))/2;
        
        int sumOfNums = 0;
        for(auto &x : nums)
            sumOfNums += x;
        
        return totalSum - sumOfNums;
    }
    
    // most optimal
    // time complexity -> O(n) space complexity -> O(1)
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int xor1=0;
        int xor2=0;
        
        for(int i=0; i<n; i++){
            
            xor1 = xor1 ^ (i+1);
            xor2 = xor2 ^ nums[i];
        }
        
        return xor1 ^ xor2;
    }
};