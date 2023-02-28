bool isAllotmentPossible(vector<long long>& cost, long long mid, int A){

    long long time = 0;
    int painter = 1;

    for(int i=0; i<cost.size(); i++){

        if(time + cost[i] > mid){
            time = cost[i];
            painter++;
        }
        else time += cost[i];

        if(painter > A) return false;
    }

    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {

    // A -> no of painters
    // B -> time taken to complete 1 unit of work
    // C -> C[i] -> length of units to paint

    int size = C.size();

    vector<long long> cost(size, 0);
    for(int i=0; i<size; i++){
        cost[i] = (1LL * C[i] * B);
    }

    long long min_time = 0;
    long long max_time = 0;

    for(int i=0; i<size; i++){
        if(cost[i] > min_time) min_time = cost[i];
        max_time += cost[i];
    }

    long long res;
    while(min_time <= max_time){

        long long mid = min_time + (max_time - min_time) / 2;

        if(isAllotmentPossible(cost, mid, A)){
            res = mid;
            max_time = mid - 1;
        }
        else{
            min_time = mid + 1;
        }
    }

    int mod = 1e7+3;
    return res % mod;
}