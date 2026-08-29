class Solution {
public:
    int expand(int i, int j, string &s){
        int n = s.length();
        int maxi = 0;

        while(i >= 0 && j < n && s[i] == s[j]){
            int len = j-i+1;
            maxi = max(len,maxi);
            i--; j++;
        }
        return maxi;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int len1 = expand(i,i,s);
            int len2 = expand(i,i+1,s);

            if(len1 > maxi){
                start = i - len1/2;
                maxi = len1;
            }
            if(len2 > maxi){
                start = (i+1) - len2/2;
                maxi = len2;
            }
        }

        string ans = "";

        for(int i = start; i < start + maxi; i++){
            ans += s[i];
        }

        return ans;
    }
};