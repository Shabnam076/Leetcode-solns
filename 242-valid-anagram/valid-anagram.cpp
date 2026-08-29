class Solution {
public:
    
    //TC : O(n), SC : O(N)
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,int> mp;

        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto it : mp){
            if(it.second != 0) return false;
        }
        
        return true;
    }
    

    /*
    //TC : O(2n), SC : O(N)
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
    */
    /*
    
    //TC : O(NlogN),  SC : O(1) -> if recursion stack space is ignored
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s == t;
    }
    */
};