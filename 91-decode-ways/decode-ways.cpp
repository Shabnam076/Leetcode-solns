class Solution {
public:
//tabulation
typedef long long int ll;
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        dp[n] = 1;

        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            ll take1 = dp[i+1];  //take 1 digit starting from i 

            ll take2 = 0;
            ll num = stoi(s.substr(i,2)); //take 2 digit starting from i
            if(i+1 <= n-1 && (num >= 10 && num <= 26)) take2 = dp[i+2];

            dp[i] = take1 + take2;
        }

        return dp[0];  
    }
};