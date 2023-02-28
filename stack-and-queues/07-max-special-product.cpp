int Solution::maxSpecialProduct(vector<int> &a) {

    int n = a.size();

    long long ngr[n]; // next greater right indexes
    for(int i=n-1; i>=0; i--){
        // remove all the smaller elements before
        while(st.size() > 0 && a[st.top()] <= a[i]) st.pop();

        if(st.size() == 0){
            ngr[i] = -1;
        }
        else{
            ngr[i] = st.top();
        }

        st.push(i);
    }

    while(st.size()>0) st.pop(); // clearing the stack

    long long ngl[n]; // next greater left indexes
    for(int i=0; i<n; i++){

        while(st.size()>0 && a[st.top()] <= a[i]) st.pop();

        if(st.size()==0){
            ngl[i] = -1;
        }
        else{
            ngl[i] = st.top();
        }

        st.push(i);
    }

    long long ans=0;
    long long mod = 1e9+7;

    for(int i=0; i<n; i++){
        if(ngl[i] != -1 && ngr[i] != -1){
            ans = max(ans, ngl[i] * 1LL * ngr[i]);
        }
    }

    ans = ans % mod;
    return ans;
    
}