class Solution {
public:
    long long f(int i, int buy, int cap,vector<int> &prices,vector<vector<vector<long long>>> &dp){
        int n = prices.size();

        if(cap == 0)return 0;
        if(i == n)return 0;
        
        if(dp[i][buy][cap] != -1)return dp[i][buy][cap];

        long long profit = 0;
        if(buy){
            profit = max(-prices[i] + f(i+1,0,cap,prices,dp), f(i+1,1,cap,prices,dp));
        }

        else{
            profit = max(prices[i] + f(i+1,1,cap-1,prices,dp),f(i+1,0,cap,prices,dp));
        }

        return dp[i][buy][cap] =  profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(2,vector<long long>(3,-1)));
        return (int)f(0,1,2,prices,dp);    
    }
};