class Solution {
public:
typedef long long int ll;
    //tabulation
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(amount+1,-1));

        for(int j = 1; j < amount+1; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                unsigned long long take = 0;
                if(j >= coins[i-1]) take = dp[i][j - coins[i-1]];
                
                unsigned long long nt = dp[i-1][j];
                dp[i][j] = take + nt;
            }
        }

        return dp[n][amount];
    }
};