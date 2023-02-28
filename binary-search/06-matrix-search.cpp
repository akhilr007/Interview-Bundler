int Solution::searchMatrix(vector<vector<int> > &arr, int target) {

    // time complexity -> O(log(m*n)) space complexity -> O(1)
    int rows = arr.size();
    int cols = arr[0].size();

    int low = 0, high = rows * cols - 1;

    while(low <= high){

        int mid = low + (high - low)/2;

        // extract row and col from mid
        int row = mid / cols;
        int col = mid % cols;

        if(arr[row][col] == target) return 1;

        if(arr[row][col] > target) high = mid - 1;
        else low = mid + 1;
    }

    return 0;
}