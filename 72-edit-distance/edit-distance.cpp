class Solution {
public:
    //memoisation 
    int opn(int i, int j, string &word1, string &word2,vector<vector<int>> &dp){
        if(j == 0){
            return i;
        }
        if(i == 0)return j;

        if(dp[i][j] != -1)return dp[i][j];

        int replace = INT_MAX;
        int del = INT_MAX;
        int insert = INT_MAX;
        
        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = opn(i-1, j-1, word1, word2,dp);    
        }
        else{
            replace = 1 + opn(i-1,j-1,word1,word2,dp);
            del = 1 + opn(i-1,j,word1,word2,dp);
            insert = 1 + opn(i,j-1,word1,word2,dp);
        }

        return dp[i][j] = min(del, min(replace, insert));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return opn(m,n,word1,word2,dp); 
    }
};