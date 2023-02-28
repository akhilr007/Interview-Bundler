// pow(x, n) -> x^n

class Solution{
    double helper(int x, int n){
        if(n == 0) return 1;
        if(x == 0) return 0;

        double res = helper(x, n/2);
        res = res*res;
        if(n%2) return x * res;

        return res;
    }
    
    double myPow(int x, int n){
        double res = helper(x, abs(n));
        if(n<0){
            return 1/res;
        }

        return res;
    }
};