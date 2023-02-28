int Solution::findMin(const vector<int> &arr) {

    int size = arr.size();

    int leftPointer = 0;
    int rightPointer = size-1;

    // edge case -> if arr is sorted
    if(arr[leftPointer] <= arr[rightPointer]) return arr[leftPointer];

    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer)/2;

        if(arr[mid-1] > arr[mid]) return arr[mid];

        if(arr[leftPointer] <= arr[mid]){
            leftPointer = mid;
        }
        else{
            rightPointer = mid;
        }
    }

    return -1;
}