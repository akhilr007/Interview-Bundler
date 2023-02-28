int binarySearchAscending(vector<int>&arr, int left, int right, int target){

    while(left <= right){

        int mid = left + (right - left)/2;

        if(arr[mid] == target) return mid;

        if(arr[mid] > target) right = mid-1;
        else left = mid + 1;
    }

    return -1;
}

int binarySearchDescending(vector<int>& arr, int left, int right, int target){

    while(left <= right){

        int mid = left + (right - left)/2;

        if(arr[mid] == target) return mid;

        if(arr[mid] > target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int Solution::solve(vector<int> &arr, int target) {

    int size = arr.size();

    int leftPointer = 0;
    int rightPointer = size-1;

    // find the bitonic point in the array
    int bitonicPoint=0;
    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer)/2;

        if((mid == 0 || arr[mid] > arr[mid-1]) && (mid == size-1 || arr[mid] > arr[mid+1])){
            bitonicPoint = mid;
            break;
        }

        if(arr[mid-1] > arr[mid]){
            rightPointer = mid-1;
        }
        else{
            leftPointer = mid + 1;
        }
    }

    // search for element in 0 to bitonicPoint-1 and bitonicPoint +1 to size-1
    if(target > arr[bitonicPoint]) return -1;
    else if(target == arr[bitonicPoint]) return bitonicPoint;
    else{
        int left = binarySearchAscending(arr, 0, bitonicPoint-1, target);
        if(left != -1) return left;

        return binarySearchDescending(arr, bitonicPoint+1, size-1, target);
    }
}