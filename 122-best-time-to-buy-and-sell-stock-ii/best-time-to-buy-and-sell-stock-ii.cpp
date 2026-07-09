class Solution {
public:
    //space optimization - 2 arrays
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2,0),next(2,0);
        //base case
        next[0] = next[1] = 0;

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + next[0], next[1]);
                }

                else{
                    profit = max(prices[i] + next[1],next[0]);
                }
               curr[buy] = profit;

            }  
            next = curr; 
        }

        return next[1];
    }
};