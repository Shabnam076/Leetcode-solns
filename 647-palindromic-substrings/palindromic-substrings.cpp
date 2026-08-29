class Solution {
public:
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
};