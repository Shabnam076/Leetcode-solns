class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()) temp.push_back(nums[i]);

            else{
                int p = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();  // lower_bound() → iterator deta hai
                                                                                        //iterator - begin() → index deta hai
                temp[p] = nums[i];        
            }
        }

        return temp.size();
    }
    /*
    //Memoization - O(n²), O(n)
    int f(int i, int last, vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        //base case
        if(i == n) return 0;
        
        if(dp[i][last] != -1)return dp[i][last];

        int take = 0;
        if(last == n || nums[i] > nums[last]) take = 1 + f(i+1, i, nums,dp);
        int nt = f(i+1, last, nums,dp);

        return dp[i][last] = max(take, nt);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0, n, nums,dp);
    }
    */
};