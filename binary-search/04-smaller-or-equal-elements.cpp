int Solution::solve(vector<int> &arr, int target) {

    int size = arr.size();
    int count = 0;

    int leftPointer = 0;
    int rightPointer = size-1;

    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer)/2;

        if(arr[mid] <= target){
            count += mid - leftPointer + 1;
            leftPointer = mid + 1;
        }
        else{
            rightPointer = mid - 1;
        }
    }

    return count;
}