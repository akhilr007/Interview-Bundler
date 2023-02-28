vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    vector<int> result;
    deque<int> d;

    int L=0, R=0;

    while(R<A.size()){

        while(d.size()>0 && d.back() < A[j]) d.pop();

        d.push_back(A[j]);

        if(R-L+1 < B){
            R++;
        }
        else if(R-L+1 == B){
            result.push_back(d.front());
            if(A[L] == d.front()){
                d.pop_front();
            }

            L++;
            R++;
        }
    }
    return result;

}