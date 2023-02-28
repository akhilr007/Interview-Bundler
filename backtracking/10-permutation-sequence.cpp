class Solution{
// brute force -> generate all permutations and sort the solution
// TC -> O(n! for permutation * n for n elements) and nlogn for sorting
public:
    // TC -> O(n^2 n for iterating the n numbers in array and n for erase) SC -> O(n) for numbers
    string permutationSequence(int n, int k){
        
        int fact = 1;
        vector<int> numbers;

        for(int i=1; i<n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }

        numbers.push_back(n);

        k = k-1;
        string ans = "";

        while(true){

            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + (k / fact));

            if(numbers.size() == 0) break;

            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};