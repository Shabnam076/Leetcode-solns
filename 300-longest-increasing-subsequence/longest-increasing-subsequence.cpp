class Solution {
public:
    int f(int i, int last, vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        
        if(i > n)return 0;
        
        if(dp[i][last] != -1)return dp[i][last];
        
        int take = 0;
        if(last == 0 || nums[i-1] > nums[last - 1]) take = 1 + f(i+1,i,nums,dp);
        
        int nt = f(i+1,last,nums,dp);
        
        return dp[i][last] = max(take, nt);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
      
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       return f(1,0,nums,dp);
        
    }
};