class Solution {
public:

    //tabulation - O(n), O(n)
    int climbStairs(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        if(n > 1) dp[1] = 2;

        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n-1];
    }

    // //recursive soution - O(2^n), O(n)
    // int f(int i){
    //     //boundary condition
    //     if(i < 0)return 0;

    //     //base case
    //     if(i == 0) return 1;
        
    //     //possible things to do on the index
    //     int left = f(i-1) + 1;
    //     int right = f(i-2) + 1;

    //     return left + right //returning value of the function
    // }

    // int climbStairs(int n) {
    //     return f(n-1);
    
    // }
     
};

