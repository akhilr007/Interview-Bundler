long long mod(long long x, long long m){
    return (((x % m) + m) % m);
}

long long multiply(long long a, long long b, long long m){

    return mod((mod(a, m) * mod(b, m)), m);
}

int modPower(int x, int y, int m){

    if(y == 0) return mod(1LL, m);
    if(y == 1) return mod(x, m);

    long long res = modPower(x, y/2, m);
    res = multiply(res, res, m);

    if(y % 2 == 1){
        res = multiply(res, x, m);
    }

    return res;
}

int Solution::pow(int x, int n, int d) {

    int M = d;
    if(x == 0) return 0;
    return modPower(x, n, M);
}