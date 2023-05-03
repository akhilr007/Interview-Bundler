class Solution {
public:
    // time complexity -> O(n^2)
    int brute(vector<int>& prices) {

        /*
            1. for each i, we can say that prices[i] is the buying day
            2. and for each j = i+1 to n, we can say that any of these can be 
                our selling day.
            3. then, we can calculate the curProfit = prices[j] - prices[i] and
                find which gives the maxProfit
        */

        int n = prices.size();

        int maxProfit = 0;

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){

                int curProfit = prices[j] - prices[i];
                maxProfit = max(maxProfit, curProfit);
            }
        }

        return maxProfit;
    }

    // time complexity -> O(n)
    int maxProfit(vector<int>& prices){

        /*
            1. here,we can maintain a minPrice that gives the buying day for which
            the price is minimum

            2. we try to calculate the curProfit = prices[i] - minPrice and if greater
            than maxProfit we allocate the value to it.

            3. and at the same time, we also find minPrice as we go forward
        */

        int n = prices.size();

        int maxProfit = 0;
        int minPrice = prices[0];

        for(int i=1; i<n; i++) {

            int curProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, curProfit);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};