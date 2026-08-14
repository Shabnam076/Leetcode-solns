class Solution {
public:
typedef long long int ll;

    ll ways(int i, string &s, vector<int> &dp){
        int n = s.length();
        if(i == n) return 1;
        if(s[i] == '0')return 0;

        if(dp[i] != -1) return dp[i];

        ll take1 = ways(i+1,s,dp);  //take 1 digit starting from i 

        ll take2 = 0;
        ll num = stoi(s.substr(i,2)); //take 2 digit starting from i
        if(i+1 <= n-1 && (num >= 10 && num <= 26)) take2 = ways(i+2,s,dp);

        return dp[i] = take1 + take2;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return ways(0,s,dp);  
    }
};