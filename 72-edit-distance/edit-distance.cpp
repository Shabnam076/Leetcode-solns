class Solution {
public:
    //Tabulation
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 0; i <= n; i++){   //0th row
            dp[0][i] = i;
        }
        for(int i = 0; i <= m; i++){   //0th column
            dp[i][0] = i;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];    
                }
                else{
                    int replace = 1 + dp[i-1][j-1];
                    int del = 1 + dp[i-1][j];
                    int insert = 1 + dp[i][j-1];
                    dp[i][j] = min(replace,min(del,insert));
                }
            }
        }
        return dp[m][n];
    }
};