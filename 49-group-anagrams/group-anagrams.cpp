class Solution {
public:

    //Tc : O(N × K log K), K -> length of each string, N =  total no of elements in vector
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < n; i++){
            string cur = strs[i];
            sort(cur.begin(), cur.end());

            mp[cur].push_back(strs[i]);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
    
    /*
    // Tc : anagram checking : O(n3) + erase opn : O(n2) , overall = O(n3)
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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;

        while(true){
            if(strs.size() == 0) break;

            for(int i = 0; i < strs.size(); i++){
                vector<string> str;
                str.push_back(strs[i]);
                for(int j = i+1; j < strs.size(); j++){
                    if(isAnagram(strs[i],strs[j])){
                        str.push_back(strs[j]);
                        strs.erase(strs.begin() + j);
                        j--;
                    }
                }
                strs.erase(strs.begin());
                ans.push_back(str);
                break;
            }
        }

        return ans;  
    }
    */
};