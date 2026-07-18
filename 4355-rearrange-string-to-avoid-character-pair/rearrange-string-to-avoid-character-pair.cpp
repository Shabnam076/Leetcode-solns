class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.length();
        if(n == 1)return s;
        unordered_map<char,int> mp;

        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        if(mp[x] > 0 && mp[y] > 0){
            string ans = "";
            while(mp[y]){
                ans += y;
                mp[y]--;
            }
            for(int i = 0; i < n; i++){
                if(s[i] != y) ans += s[i];
            }
            return ans;
        }
        return s;
        
    }
};