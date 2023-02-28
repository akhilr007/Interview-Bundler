vector<int> Solution::searchRange(const vector<int> &arr, int target) {

    int size = arr.size();

    int leftPointer = 0;
    int rightPointer = size-1;

    int firstIndex = -1;
    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer) / 2;

        if(arr[mid] == target){
            firstIndex = mid;
            rightPointer = mid - 1;
        }
        else if(arr[mid] > target){
            rightPointer = mid - 1;
        }
        else{
            leftPointer = mid + 1;
        }
    }

    leftPointer = 0;
    rightPointer = size - 1;

    int secondIndex = -1;
    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer)/2;

        if(arr[mid] == target){
            secondIndex = mid;
            leftPointer = mid + 1;
        }
        else if(arr[mid] > target){
            rightPointer = mid - 1;
        }
        else{
            leftPointer = mid + 1;
        }
    }

    vector<int> indexes(2);
    if(firstIndex == -1 and secondIndex == -1){
        indexes[0] = -1, indexes[1] = -1;
    }
    else{
        indexes[0] = firstIndex;
        indexes[1] = secondIndex;
    }

    return indexes;
}