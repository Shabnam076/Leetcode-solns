class Solution {
public:
    
    //DP
    // TC : O(N2) , SC : O(N2)
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(i == j) dp[i][j] = true;
                else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j] == true) cnt++;
            }
        }
        return cnt;
    }
    /*

    // TC: O(N²) — N possible centers × up to O(N) expansion
    // SC: O(1) — sirf pointers aur counters use ho rahe hain
    int expand(int i, int j, string &s){
        int cnt = 0;
        int n = s.length();

        while(i >= 0 && j < n && s[i] == s[j]){
            i--; j++; cnt++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            cnt += expand(i,i,s);
            if(i + 1 < n) cnt += expand(i,i+1,s);
        }
        return cnt;
    }
    */

/*
    //Brute : ~O(n3), SC : O(N)
    bool isPalindrome(string st){
        int l = 0, r = st.length()-1;

        while(l <= r){
            if(st[l] != st[r]) return false;
            l++; r--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.length();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            string st = "";
            for(int j = i; j < n; j++){
                st += s[j];
                if(isPalindrome(st))cnt++;
            }
        }
        return cnt;
    }
    */
};