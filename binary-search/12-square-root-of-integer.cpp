int Solution::sqrt(int number) {

    if(number == 0 || number == 1) return number;

    long leftPointer = 1;
    long rightPointer = number / 2;

    long squareRoot;
    while(leftPointer <= rightPointer){

        long mid = leftPointer + (rightPointer - leftPointer) / 2;

        if(mid * mid == number) return mid;

        if(mid * mid < number){
            squareRoot = mid;
            leftPointer = mid + 1;
        }
        else{
            rightPointer = mid - 1;
        }
    }

    return squareRoot;
}