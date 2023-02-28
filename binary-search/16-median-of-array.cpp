double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {

    if(A.size() > B.size()) return findMedianSortedArrays(B, A);

    int N = A.size();
    int M = B.size();

    int totalSize = N + M;
    int half = totalSize / 2;

    int l = 0;
    int r = N - 1;

    while(true){

        int i = l > r ? -1 : (l + r) / 2; // for a
        int j = half - i - 2; // for b

        int ALeft = i >=0 ? A[i] : INT_MIN;
        int ARight = i+1 < N ? A[i+1] : INT_MAX;
        int BLeft = j >= 0 ? B[j] : INT_MIN;
        int BRight = j+1 < M ? B[j+1] : INT_MAX;

        if(ALeft <= BRight && BLeft <= ARight){

            if(totalSize % 2){
                // odd 
                return min(ARight, BRight) * 1.0;
            }
            else{
                return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
            }
        }
        else if(ALeft > BRight){

            r = i - 1;
        }
        else{

            l = i + 1;
        }

    }

    return 0.0;
}