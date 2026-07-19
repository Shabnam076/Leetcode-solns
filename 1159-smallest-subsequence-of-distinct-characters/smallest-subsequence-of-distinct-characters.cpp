class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_map<char,int> f;

        for(char c : s){
            f[c]++;
        }

        stack<char> st;
        vector<bool> vis(26, false);
        for(int i = 0; i < n; i++){
            f[s[i]]--;
            if (vis[s[i] - 'a']) continue;
            while(!st.empty() && s[i] < st.top() && f[st.top()] > 0){
                vis[st.top() - 'a'] = false;
                st.pop();

            }
            st.push(s[i]);
            vis[s[i] - 'a'] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};