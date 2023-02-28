bool isAllotmentPossible(vector<int>& arr, int maximumPagesAllowed, int totalStudentsAllowed){

    int numberOfStudentsAtPresent = 1;
    int currPages = 0;

    for(int i=0; i<arr.size(); i++){

        if(currPages + arr[i] > maximumPagesAllowed){
            currPages = arr[i];
            numberOfStudentsAtPresent++;
        }
        else currPages += arr[i];

        if(numberOfStudentsAtPresent > totalStudentsAllowed) return false;
    }

    return true;
}

int Solution::books(vector<int> &arr, int totalStudentsAllowed) {

    // every student should have at least 1 book
    if(arr.size() < totalStudentsAllowed) return -1;

    int leftPointer = 0;
    int rightPointer = 0;
    for(int i=0; i<arr.size(); i++){
        leftPointer = max(leftPointer, arr[i]);
        rightPointer += arr[i];
    }

    int res=-1;
    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer)/2;

        if(isAllotmentPossible(arr, mid, totalStudentsAllowed)){
            res = mid;
            rightPointer = mid - 1;
        }
        else{
            leftPointer = mid + 1;
        }
    }

    return res;
}