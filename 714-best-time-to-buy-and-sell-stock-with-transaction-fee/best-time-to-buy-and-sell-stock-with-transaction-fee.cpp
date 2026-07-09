class Solution {
public:
    typedef long long int ll;
    ll f(int i, int buy, int &fee, vector<int> &prices,vector<vector<ll>> &dp){
        int n = prices.size();
        if(i == n) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        ll profit = 0;
        if(buy){
            profit = max((ll)-prices[i] + f(i+1,0,fee,prices,dp),(ll) f(i+1,1,fee,prices,dp));
        }
        else{
            profit = max((ll) prices[i] - fee + f(i+1,1,fee,prices,dp),(ll)f(i+1,0,fee,prices,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return (int)f(0,1,fee,prices,dp);
        
    }
};