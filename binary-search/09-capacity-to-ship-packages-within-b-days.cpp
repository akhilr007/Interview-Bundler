bool isAllotmentPossible(vector<int>& arr, int maxWeight, int maxDays){

    int days = 1;
    int totalWeight = 0;

    for(int i=0; i<arr.size(); i++){

        if(totalWeight + arr[i] > maxWeight){
            totalWeight = arr[i];
            days++;
        }
        else totalWeight += arr[i];
    }

    if(days > maxDays) return false;
    return true;
}

int Solution::solve(vector<int> &arr, int B){

    int leftPointer = 0, rightPointer = 0;
    for(int i=0; i<arr.size(); i++){
        leftPointer = max(leftPointer, arr[i]);
        rightPointer += arr[i];
    }

    int minWeightCapacity;

    while(leftPointer <= rightPointer){

        int mid = leftPointer + (rightPointer - leftPointer)/2;

        if(isAllotmentPossible(arr, mid, B)){
            minWeightCapacity = mid;
            rightPointer = mid - 1;
        }
        else{
            leftPointer = mid + 1;
        }
    }

    return minWeightCapacity;
}