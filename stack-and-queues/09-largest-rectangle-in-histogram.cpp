int Solution::largestRectangleArea(vector<int> &a) {

    int n = a.size();
    stack<int> st;

    int nsl[n];
    for(int i=0; i<n; i++){

        // remove all the greater elements than a[i]
        while(st.size()>0 && a[st.top()] >= a[i]) st.pop();

        if(st.size() == 0){
            nsl[i] = -1;
        }
        else{
            nsl[i] = st.top();
        }

        st.push(i);
    }

    while(st.size()>0) st.pop();

    int nsr[n]; // next smaller right indexes
    for(int i=n-1; i>=0; i--){

        // remove all the greater elements than a[i]
        while(st.size()>0 && a[st.top()] >= a[i]) st.pop();

        if(st.size() == 0){
            nsr[i] = n;
        }
        else{
            nsr[i] = st.top();
        }

        st.push(i);
    }

    long long maxArea = 0;
    for(int i=0; i<n; i++){

        long long height = a[i];
        long long width = (nsr[i] - nsl[i]) - 1;

        long long curArea = height * 1LL * width;
        maxArea = max(maxArea, curArea);
    }

    return maxArea;
}