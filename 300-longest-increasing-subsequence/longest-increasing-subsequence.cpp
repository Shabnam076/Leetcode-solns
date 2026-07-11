class Solution {
public:
    //Tabulation
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));

        for(int i = n; i >= 1; i--){
            for(int last = 0; last < i; last++){
                int take = 0;
                if(last == 0 || nums[i-1] > nums[last-1]) take = 1 + dp[i+1][i];
                int nt = dp[i+1][last];

                dp[i][last] = max(take,nt);
            }
        }
        return dp[1][0];
    }
};