class Solution {
public:
    //2-d optimised
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<unsigned long long> prev(n+1,0);

        prev[0] = 1;

        for(int i = 1; i <= m; i++){
            for(int j = n; j >= 1; j--){
                if(s[i-1] == t[j-1]) prev[j] = prev[j-1] + prev[j];
                else prev[j] = prev[j];
            }
        }
        return (int)prev[n];
    }
};