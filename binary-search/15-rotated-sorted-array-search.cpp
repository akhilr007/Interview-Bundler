int Solution::search(const vector<int> &arr, int target) {

    int size = arr.size();

    int leftPointer = 0;
    int rightPointer = size - 1;

    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer) / 2;

        if(arr[mid] == target){
            return mid;
        }

        if(arr[leftPointer] <= arr[mid]){
            // left to mid is sorted -> perform search in sorted space
            if(target >= arr[leftPointer] && target <= arr[mid]){
                rightPointer = mid - 1;
            }
            else{
                leftPointer = mid + 1;
            }
        }
        else if(arr[mid] <= arr[rightPointer]){
            if(target >= arr[mid] && target <= arr[rightPointer]){
                leftPointer = mid + 1;
            }
            else{
                rightPointer = mid - 1;
            }
        }
    }

    return -1;
}