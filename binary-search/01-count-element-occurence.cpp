int Solution::findCount(const vector<int> &arr, int target) {
    
    int size = arr.size();
    
    int firstOccurrence = -1;
    
    int lowPointer = 0;
    int highPointer = size-1;
    
    while(lowPointer <= highPointer){
        
        int mid = lowPointer + (highPointer - lowPointer)/2;
        
        if(arr[mid] == target){
            firstOccurrence = mid;
            highPointer = mid-1;
        }
        
        else if(arr[mid] > target){
            highPointer = mid-1;
        }
        else{
            lowPointer = mid + 1;
        }
    }
    
    lowPointer = 0;
    highPointer = size-1;
    int lastOccurrence = -1;
    
    while(lowPointer <= highPointer){
        
        int mid = lowPointer + (highPointer - lowPointer)/2;
        
        if(arr[mid] == target){
            lastOccurrence = mid;
            lowPointer = mid+1;
        }
        
        else if(arr[mid] > target){
            highPointer = mid - 1;
        }
        else{
            lowPointer = mid + 1;
        }
    }
    
    if(firstOccurrence == -1 and lastOccurrence == -1) return 0;
    return lastOccurrence - firstOccurrence + 1;
    
}
