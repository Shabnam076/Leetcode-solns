class Solution {
public:
    //tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(3,0)));

        //since dp is initialized with 0, base case is covered already, we just have to make sure that we dont
        ///overwrite it: so i : 0 to n-1, buy = 0 to 1, cap = 1 to 2.
        //i == n and cap = 0 is the base case so we will not run the code for these.

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    long long profit = 0;
                    if(buy){
                        profit = max(-prices[i] + dp[i+1][0][cap],dp[i+1][1][cap]);
                    }

                    else{
                        profit = max(prices[i] + dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }

                    dp[i][buy][cap] =  profit;

                }
            }
        }

        return (int)dp[0][1][2];    
    }
};