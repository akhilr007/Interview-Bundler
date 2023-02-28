// selection sort 
// time complexity -> O(n^2)

// it pushes minimum to the front
void selection_sort(vector<int>& nums){

    int n = nums.size();

    // iterate till n-2 elements
    for(int i=0; i<=n-2; i++){

        // let min_value to be current element
        int min_index = i;

        // find min_value between [i, n-1]
        for(int j=i; j<=n-1; j++){

            if(nums[j] < nums[min_index]){
                min_index = j;
            }
        }

        // swap min_value with current element
        swap(nums[min_index], nums[i]);
    }
}