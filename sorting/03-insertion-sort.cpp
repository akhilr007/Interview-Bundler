// insertion sort 
// worst time complexity -> O(n^2) | best time complexity -> O(n)

void insertion_sort(vector<int>& arr){

    int n = arr.size();

    for(int i=0; i<=n-1; i++){

        int j=i;

        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}