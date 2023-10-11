#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

bool isPrime(int n){

	for(int i=2; i*i<=n; i++){
		if(n % i == 0){
			return false;
		}
	}

	return n > 1;
}

// O(n log log n)
void sieve(int n){

	bool primes[n+1];
	fill(primes, primes+n+1, true);

	primes[0] = primes[1] = false;

	for(int i=2; i<=n; i++){

		if(primes[i]){
			cout << i << " ";
			for(int j=i*i; j<=n; j+=i){
				primes[j] = false;
			}
		}
	}
}

void factorize(int n){

	for (long long i = 2; i * i <= n; ++i){

		while(n % i == 0){

			cout << i << endl;
			n /= i;
		}
	}

	if (n > 1){

		cout << n << endl;
	}
}

void missingNumber1(int n, int arr[]){

	int sumOfN = n * (n+1)/2;

	int sumOfArr = 0;
	for(int i=1; i<n; i++){
		sumOfArr += arr[i];
	}

	int result = sumOfN - sumOfArr;
	cout << result;
}

void missingNumber2(int n, int arr[]){

	int  result = 0;
	int i;
	for(i=1; i<n; i++){
		result ^= arr[i];
		result ^= i;
	}

	result ^= i;
	cout << result;
}

int power(int a, int b){

	if(b == 0) return 1;

	int half_power = power(a, b/2);

	if(b%2==0)
		return half_power * half_power;
	else
		return half_power * half_power * a;
}

int mod_power(int a, int b){

	if(b == 0) return 1;

	a %= MOD;

	int half_power = power(a, b/2);

	if(b%2==0)
		return half_power * half_power % MOD;
	else
		return half_power * half_power % MOD * a % MOD;
}

int gcd(int a, int b){
	if(a==0)
		return b;

	return gcd(b%a, a);
}

int lcm(int a, int b){
	return (a * b) / gcd(a, b);
}

int main(){

	int a, b;
	cin >> a >> b;

	cout << lcm(a, b);


	return 0;
}