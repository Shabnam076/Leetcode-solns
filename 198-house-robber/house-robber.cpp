class Solution {
public:
    //Tabulation - O(n), O(n)

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        dp[0] = nums[0];
        if(n > 1) dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            int take = nums[i] + dp[i-2];
            int nt = dp[i-1];

            dp[i] = max(take,nt);
        }
        return dp[n-1];
    }
};



