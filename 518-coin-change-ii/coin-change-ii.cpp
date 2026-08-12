class Solution {
public:
    //memoization
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0)return 1;
        //base case
        if(i == 1){
            if(amount % coins[i-1] == 0) return 1;
            else return 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 0;
        if(amount >= coins[i-1]) take = f(i, amount - coins[i-1], coins,dp);
        
        int nt = f(i-1, amount, coins,dp);

        return dp[i][amount] = take + nt;
    }

    int change(int amount, vector<int>& coins) {
        if(amount == 0)return 1;

        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return f(n,amount,coins,dp);
    }
};