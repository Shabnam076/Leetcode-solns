class Solution {
public:
    //tabulation - O(n*m), O(n*m)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int same = 0;
                if(text1[i] == text2[j]){     //both char same
                    same = 1 + dp[i+1][j+1];
                }
                else{   //both char not same
                    same = max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = same;
            }
        }
        return dp[0][0];
    }
};