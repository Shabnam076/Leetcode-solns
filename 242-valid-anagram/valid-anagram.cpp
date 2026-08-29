class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;

        for(int i = 0; i < s.length(); i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }

        for(int i = 0; i < t.length(); i++){
            if(mps[t[i]] != mpt[t[i]]) return false;
        }

        return true;
        
    }
};