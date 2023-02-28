int Solution::findMedian(vector<vector<int> > &arr) {

    int rows = arr.size();
    int cols = arr[0].size();

    int size = rows * cols;

    int leftValue = 1;
    int rightValue = 1e9;

    while(leftValue <= rightValue){

        int midValue = (leftValue + rightValue) / 2;

        int ans=0;
        for(int i=0; i<rows; i++){

            int low = 0;
            int high = cols - 1;

            // search number of values lesser than midValue
            while(low <= high){

                int m = low + (high - low) / 2;

                if(arr[i][m] <= midValue) low = m + 1;
                else high = m - 1;
            }

            ans += l;
        }

        if(ans <= size/2) leftValue = midValue + 1;
        else rightValue = midValue - 1;
    }

    return leftValue;
}