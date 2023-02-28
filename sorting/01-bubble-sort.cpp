// sort an array
// bubble sort -> complexity -> O(n^2) for worst case for best case O(n)

// it pushes maximum to the end of the array

void bubble_sort(vector<int>& arr){

    int n = arr.size();

    // [0 - n-1], [0 - n-2], [0, n-3] ... [0, 1]
    for(int i=n-1; i>=0; i--){

        int didSwap = 0;
        for(int j=0; j<=i-1; j++){

            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }

        if(didSwap == 0)
            break;
    }
}