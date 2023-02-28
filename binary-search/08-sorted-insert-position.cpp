int Solution::searchInsert(vector<int> &arr, int target) {

    int size = arr.size();

    int rightPosition = size;

    int leftPointer = 0;
    int rightPointer = size - 1;

    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer) / 2;

        if(arr[mid] >= target){
            rightPosition = mid;
            rightPointer = mid - 1;
        }
        else{
            leftPointer = mid + 1;
        }
    }

    return rightPosition;
}