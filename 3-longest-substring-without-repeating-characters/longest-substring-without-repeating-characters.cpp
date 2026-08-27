class Solution {
public:
    //Further optimized only if interviewer ask to 
    //O(n) time and O(k) space
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;

        //sliding window
        int l = 0, r = 0, maxi = 0;
        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]] + 1);    // why max? - // try on this string = 'abba'
            }
            mp[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }

        return maxi;
    }

    /*
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;

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
    */

};