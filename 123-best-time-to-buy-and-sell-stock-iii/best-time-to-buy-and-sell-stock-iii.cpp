class Solution {
public:
    //tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(3,0)));

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