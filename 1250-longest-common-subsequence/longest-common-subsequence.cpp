class Solution {
public:
    //memoization - O(n*m), O(n*m) + O(n+m)
    int f(int i, int j, string &text1, string &text2,vector<vector<int>> &dp){
        int n = text1.length();
        int m = text2.length();

        if(i >= n || j >= m)return false;

        if(dp[i][j] != -1)return dp[i][j];

        int same = 0;
        if(text1[i] == text2[j]){     //both char same
            same = 1 + f(i+1,j+1,text1,text2,dp);
        }
        else{   //both char not same
            same = max(f(i,j+1,text1,text2,dp), f(i+1,j,text1,text2,dp));
        }

        return dp[i][j] = same;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,text1,text2,dp);
    }
};