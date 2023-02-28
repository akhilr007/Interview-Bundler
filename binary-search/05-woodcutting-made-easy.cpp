bool woodObtainedGreaterOrEqual(vector<int>& arr, int cutHeight, int target){

    int woodObtained=0;
    for(int treeHeight : arr){

        if(treeHeight >= cutHeight){
            woodObtained += (treeHeight - cutHeight);
        }

        if(woodObtained >= target) return true;
    }

    return false;
}

int Solution::solve(vector<int> &arr, int target) {

    int low = 0;
    int high = 0;
    for(int i=0; i<arr.size(); i++){
        high = max(high, arr[i]);
    }

    int maximumHeight;

    while(low <= high){

        int mid = low + (high - low)/2;

        if(woodObtainedGreaterOrEqual(arr, mid, target)){
            maximumHeight = mid; // store ans
            low = mid + 1; // increase the height so that we can get not more than target wood
        }
        else{
            high = mid - 1; // lower the height so that we can get atleast target wood.
        }
    }

    return maximumHeight;
}