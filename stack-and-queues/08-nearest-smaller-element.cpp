vector<int> Solution::prevSmaller(vector<int> &a) {

    int n = a.size();

    stack<int> st;
    vector<int> nse(n); // nearest smaller element

    for(int i=0; i<n; i++){

        // to find smaller, we need to remove all the greater elements than a[i]
        while(st.size() > 0 && st.top() >= a[i]) st.pop();

        if(st.size() == 0){
            nse[i] = -1;
        }
        else{
            nse[i] = st.top();
        }

        st.push(a[i]);
    }

    return nse;
}