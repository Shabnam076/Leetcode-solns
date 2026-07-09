class Solution {
public:
    //space optimization - 4 variables
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nextNotBuy = 0, nextBuy = 0;       //i+1 th row
        int currNotBuy = 0, currBuy = 0;     //i th row 
        
        for(int i = n-1; i >= 0; i--){
            currBuy = max(-prices[i] + nextNotBuy, nextBuy);   //buy = 1

            currNotBuy = max(prices[i] + nextBuy,nextNotBuy);   //buy = 0

            nextNotBuy = currNotBuy;
            nextBuy = currBuy;  
        }

        return nextBuy;
    }
};