// time complexity -> Worst Case : O(n^2)  | Best or Average Case : O(nlogn)

class Solution{

    int partition(int[] arr, int low, int high){

        int pivot = arr[low]; // selecting the first element as pivot

        int l = low;
        int r = high;

        while(l < r){

            // pick first greater element from left
            while(arr[l] <= pivot && (l <= high))
                l++;

            // pick first smaller element from right
            while(arr[r] > pivot && (r >= low))
                r--;

            if(l < r) swap(arr[l], arr[r]);
        }
        
        // r is the pIndex which is the correct place for pivot
        swap(arr[low], arr[r]);
        return r;
    }

    int quickSort(int[] arr, int low, int high){

        if(low < high){

            int pIndex = partition(arr, low, high);

            quickSort(arr, low, pIndex - 1);
            quickSort(arr, pIndex + 1, high);
        }
    }

    int sortMyArray(int[] arr, int n){

        int low = 0;
        int high = n-1;

        quickSort(arr, low, high);

        return arr;
    }
}