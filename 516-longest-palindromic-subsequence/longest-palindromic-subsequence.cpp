class Solution {
public:
    //space optimized - 2d array
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(),rev.end());

        vector<int> prev(n+1,0), curr(n+1,0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == rev[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }

        return prev[n];   
    }
};