class Solution {
public:
    //1d optimised : left ->right
    //right->left wouldnt work because we require curr[j-1] for calculating curr[j], so processing has to be done from left->right
    int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<int> dp(n + 1);

    for(int j = 0; j <= n; j++)
        dp[j] = j;

    for(int i = 1; i <= m; i++) {

        int prevDiag = dp[0]; // dp[i-1][0]
        dp[0] = i;

        for(int j = 1; j <= n; j++) {

            int temp = dp[j]; // old dp[i-1][j]

            if(word1[i-1] == word2[j-1]) {
                dp[j] = prevDiag;
            }
            else {
                dp[j] = 1 + min({
                    prevDiag, // dp[i-1][j-1]
                    temp,     // dp[i-1][j]
                    dp[j-1]   // dp[i][j-1]
                });
            }

            prevDiag = temp;
        }
    }

    return dp[n];
}
};