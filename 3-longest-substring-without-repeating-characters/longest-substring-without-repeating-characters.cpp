class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int,int> mp;

        //sliding window
        int l = 0, r = 0, maxi = 0;
        while(r < n){
            mp[s[r]]++;
            while(l <= r && mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }

};