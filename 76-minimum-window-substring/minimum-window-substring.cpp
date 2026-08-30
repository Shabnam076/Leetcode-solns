class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        int hash[256] = {0};

        // t ki frequency store karo
        for(char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        while(r < n) {

            // current character required hai
            if(hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            // valid window mil gayi
            while(cnt == t.length()) {

                // minimum window update
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                // left character remove karo
                hash[s[l]]++;

                // agar required character ki frequency
                // kam ho gayi, window invalid ho jayegi
                if(hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

    if(startIndex == -1) return "";

    return s.substr(startIndex, minLen);
}

    /*
    // Brute : O(N2)
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        int n = s.length(), m = t.length();

        int minLen = INT_MAX, si = -1;

        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            int cnt = 0;
            for(int j = 0; j < m; j++){
                hash[t[j]]++;
            }
            for(int k = i; k < n; k++){
                if(hash[s[k]] > 0) cnt++;
                hash[s[k]]--;
                if(cnt == m){
                    if(k-i+1 < minLen){
                        minLen = k-i+1;
                        si = i;
                    }
                    break;
                }
            }
        }
        if(si == -1) return "";
        return s.substr(si, minLen);
    }
    */
};