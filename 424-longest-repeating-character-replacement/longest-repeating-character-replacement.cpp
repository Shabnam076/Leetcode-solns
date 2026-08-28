class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int l = 0, r = 0, maxFreq = 0;
        int maxi = 0;
        unordered_map<char,int> mp;

        while(r < n){
            mp[s[r]]++;

            maxFreq = 0;
            for(auto it : mp){
                maxFreq = max(maxFreq,it.second);
            }

            while((r-l+1) - maxFreq > k){   //shrink the window
                mp[s[l]]--;
                l++;
            }

            maxi = max(maxi, r-l+1);
            r++;
        }

        return maxi;
        
    }
};